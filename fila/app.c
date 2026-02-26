#include <stdio.h>
#include <stdlib.h>

/** Variáveis globais. */
#define NAME 30
#define MAX 5

/** Estrutura para definir pessoa. */
typedef struct {
    char nome[NAME];
    int idade;
} Pessoa;

/** Estrutura da fila. */
typedef struct {
    Pessoa itens[MAX];
    int inicio;
    int fim;
    int total;
} Fila;

void iniciarFila(Fila *f) {
    f->inicio = 0;
    f->fim = 0;
    f->total = 0;
}

int filaCheia(Fila *f) {
    return f->total == MAX;
}

int filaVazia(Fila *f) {
    return f->total == 0;
}

void inserir(Fila *f, Pessoa p) {
    if(filaCheia(f)) {
        printf("A fila está cheia.");
        return;
    }

    f->itens[f->fim] = p;
    f->fim = (f->fim + 1) % MAX;
    f->total++;
}

void remover(Fila *f, Pessoa *p) {
    /** Valor padrão se a fila estiver vazia */
    if(filaVazia(f)) {
        return;
    }

    *p = f->itens[f->inicio];
    f->inicio = (f->inicio + 1) % MAX;
    f->total--;
}

void mostrarFila(Fila *f) {
    printf("Fila: ");

    for(int i = 0, idx = f->inicio; i < f->total; i++, idx = (idx + 1) % MAX) {
        printf("[%s, %d] ", f->itens[idx].nome, f->itens[idx].idade);
    }

    printf("\n");
}

int main() {

    Fila *f;
    iniciarFila(&f);

    Pessoa p1 = {"Alice", 38};
    Pessoa p2 = {"Bob", 42};
    Pessoa p3 = {"Camila", 19};
    Pessoa p4 = {"Larissa", 37};

    inserir(&f, p1);
    inserir(&f, p2);

    mostrarFila(&f);

    Pessoa removida;
    remover(&f, &removida);
    printf("Pessoa removida: %s %d\n", removida.nome, removida.idade);

    return 0;
}