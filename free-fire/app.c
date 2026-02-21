#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/** Define constant variables. */
#define SIZE_NAME 30
#define SIZE_TYPE 20
#define SIZE_ITEMS 10
#define GAME_OVER 0
#define REMOVE_INDEX -1

typedef struct {
    char name[SIZE_NAME];
    char type[SIZE_TYPE];
    int quanty;
}Items;

void cleanBuffer() {
    int c;
    while((c = getchar()) != '\n' && c != EOF);
};

int main() {
    Items items[SIZE_ITEMS];
    int totalItems = 0;

    int opt;

    do {
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
                if(opt != 0 && opt != 1 && opt != 2 && opt != 3) {
                    printf("Operacao invalida!");
                    return 0;
                } else if(totalItems < SIZE_ITEMS) {
                    printf("Nome do item: ");
                    fgets(items[totalItems].name, SIZE_NAME, stdin);
                    
                    printf("Tipo do item (ex: cura, municao, arma, etc): ");
                    fgets(items[totalItems].type, SIZE_TYPE, stdin);
                    
                    printf("Quantidade: ");
                    scanf("%d", &items[totalItems].quanty);
                    
                    cleanBuffer();
                    
                    items[totalItems].name[strcspn(items[totalItems].name, "\n")] = '\0';
                    items[totalItems].type[strcspn(items[totalItems].type, "\n")] = '\0';
    
                    totalItems++;

                    printf("\n--- ITENS NA MOCHILA --- %d/10\n", totalItems);
                    printf("\nNOME       | TIPO       | QUANTIDADE\n");
                    printf("------------------------------------------\n");

                    for(int i = 0; i < totalItems; i++) {
                        printf(" %s   | %s   | %d      ", items[i].name, items[i].type, items[i].quanty);
                        printf("\n------------------------------------------\n");
                        printf("\n");
                    }
                } else {
                    printf("Mochila cheia!");
                }
            break;

            case 2: 
                char removedItem[SIZE_NAME];
                int removeIndex = REMOVE_INDEX;

                printf("\nDigite o nome do item para remover: ");
                fgets(removedItem, SIZE_NAME, stdin);

                /* Find the index of the element to be removed. */
                for(int i = 0; i < totalItems; i++) {
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

                totalItems--;
                  
                /** List items  */
                printf("\n--- ITENS NA MOCHILA --- %d/10\n", totalItems);
                printf("\nNOME    | TIPO    | QUANTIDADE\n");
                printf("------------------------------------------\n");

                for(int i = 0; i < totalItems; i++) {
                    printf("%s   |    %s   |    %d   ", items[i].name, items[i].type, items[i].quanty);
                    printf("\n------------------------------------------\n");
                    printf("\n");
                }
            break;
            
            case 3:
                printf("\n--- ITENS NA MOCHILA --- %d/10\n", totalItems);
                printf("\nNOME    | TIPO    | QUANTIDADE\n");
                printf("------------------------------------------\n");

                for(int i = 0; i < totalItems; i++) {
                    printf("%s   |    %s   |    %d   ", items[i].name, items[i].type, items[i].quanty);
                    printf("\n------------------------------------------\n");
                    printf("\n");
                }
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

    } while(totalItems != SIZE_ITEMS);

    return 0;

}