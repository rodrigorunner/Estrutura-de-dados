#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/** Define constant variables. */
#define SIZE_NAME 30
#define SIZE_TYPE 20
#define SIZE_ITEMS 10
#define REMOVE_INDEX -1
#define GAME_OVER 11

/** Struct to define items */
typedef struct {
    char name[SIZE_NAME];
    char type[SIZE_TYPE];
    int quanty;
}Items;

/** Define global variable */
int totalItems;

/** Insert Item */
void insertItem(Items *i, int *totalItems) {
    if(*totalItems < SIZE_ITEMS) {
        printf("Nome do item: ");
        fgets(i[*totalItems].name, SIZE_NAME, stdin);
        
        printf("Tipo do item (ex: cura, municao, arma, etc): ");
        fgets(i[*totalItems].type, SIZE_TYPE, stdin);
        
        printf("Quantidade: ");
        scanf("%d", &i[*totalItems].quanty);
        
        /** Clean entrance buffer */
        cleanBuffer();
        
        i[*totalItems].name[strcspn(i[*totalItems].name, "\n")] = '\0';
        i[*totalItems].type[strcspn(i[*totalItems].type, "\n")] = '\0';
        
        *totalItems = *totalItems + 1;
    } else {
        printf("Mochila cheia!");
    }
}

/** List Item */
void listItems(Items *items, int totalItems) {
    /** There's item in the bag ? */
    if(totalItems != 0) {
        printf("\n--- ITENS NA MOCHILA --- %d/10\n", totalItems);
        printf("\nNOME       | TIPO       | QUANTIDADE\n");
        printf("------------------------------------------\n");

        for(int i = 0; i < totalItems; i++) {
            printf(" %s   | %s   | %d      ", items[i].name, items[i].type, items[i].quanty);
            printf("\n------------------------------------------");
            printf("\n");
        }
    } else {
        printf("\nMochila vazia...\n\n");
    }
}

/** Remove Item */
void removeItems(Items *items, int *totalItems) {
    char removedItem[SIZE_NAME];
    int removeIndex = REMOVE_INDEX;

    printf("\nDigite o nome do item para remover: ");
    fgets(removedItem, SIZE_NAME, stdin);

    /* Find the index of the element to be removed. */
    for(int i = 0; i < *totalItems; i++) {
        if(strcmp(items[i].name, removedItem) == 0) {
            removeIndex = i;
            break;
        }
    }

    if(removeIndex != REMOVE_INDEX) {
        /** 
         * Shift subsequent elements
         * Use a loop starting from the found index 
        * */
        for(int i = removeIndex; i < totalItems; i++) {
            /** Shift pointer. */
            items[i] = items[i + 1];
        }
    }

    *totalItems = *totalItems - 1;
}

void cleanBuffer() {
    int c;
    while((c = getchar()) != '\n' && c != EOF);
};

int main() {
    /** Create an array of items. */
    Items items[SIZE_ITEMS];
    /* Variable to capture the entrance option. */
    int opt;

    do {
        /** Verify capacity of the bag. */
        if(totalItems == SIZE_ITEMS) {
            printf("\nVocê deve retirar um item da mochila ou GAME OVER...\n");
        }

        printf("=============================\n");
        printf("MOCHILA SOBREVIVENCIA - CODIGO ILHA\n");
        printf("=============================\n");
        printf("Itens na mochila: %d/10\n\n", totalItems);
        printf("1. Adicionar item\n");
        printf("2. Remover item\n");
        printf("3. Listar item\n");
        printf("0. Sair\n");
        printf("-------------------\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opt);
        cleanBuffer();

        if(opt == 1) {
            printf("--- Adicionar Novo Item ---\n\n");
        }

        switch(opt) {

            case 1: 
               insertItem(&items, &totalItems);
               listItems(&items, totalItems);
            break;

            case 2:    
                removeItems(&items, &totalItems);
                listItems(&items, totalItems);
            break;
            
            case 3:
                listItems(&items, totalItems);
            break;

            case 0: 
               printf("Saindo do jogo...\n");
               return 0;
            break;
            default: 
                printf("\nOperacao invalida! Comece o jogo novamente...\n"); 
                return 0; 
            break;
        } 

        printf("Pressione enter para continuar...");
        getchar();

    } while(totalItems != GAME_OVER);

    return 0;

}