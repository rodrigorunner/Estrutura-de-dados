/**
 * Descrição: algoritmos de busca e ordenação.
 */

 /* Busca sequencial. */
 void buscaSequancial(int lista[], int tamanho, int valor) {
    for(int i = 0; i < tamanho; i++) {
        if(lista[i] == valor) {
            return i;
        }
    }
 };

 /* Busca binária. */
 void buscaBinaria(int lista[], int tamanho, int valor) {
    int inicio = 0;
    int fim = tamanho - 1;
    while(inicio <= fim) {
        int meio = (inicio + fim) / 2;
        if(lista[meio] == valor) {
            return meio;
        } else if(lista[meio] < valor) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }
 }

 /* Ordenação - função básica para trocar valor. */
 void trocar(int* a, int* b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
 }

 /* Bubble Sort */
 bubblesort(int lista[], int tamanho) {
    for(int i = 0; i < tamanho - 1; i++) {
        for(int j = 0; j < tamanho - 1 - i; j++) {
            trocar(&lista[j], &lista[j + 1]);
        }
    }
 }