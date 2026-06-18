#include <stdio.h>

void merge(int v[], int inicio, int meio, int fim) {
    int aux[10];
    int i = inicio;
    int j = meio + 1;
    int k = inicio;

    while (i <= meio && j <= fim) {
        if (v[i] <= v[j]) {
            aux[k] = v[i];
            i++;
        } else {
            aux[k] = v[j];
            j++;
        }
        k++;
    }

    while (i <= meio) {
        aux[k] = v[i];
        i++;
        k++;
    }

    while (j <= fim) {
        aux[k] = v[j];
        j++;
        k++;
    }

    for (i = inicio; i <= fim; i++) {
        v[i] = aux[i];
    }
}

void mergeSort(int v[], int inicio, int fim) {
    if (inicio < fim) {
        int meio = (inicio + fim) / 2;

        mergeSort(v, inicio, meio);
        mergeSort(v, meio + 1, fim);

        merge(v, inicio, meio, fim);
    }
}

int main() {
    int v[10];
    int i;
    int menor, maior;
    int contMenor = 0, contMaior = 0;

    // Leitura dos 10 valores
    for (i = 0; i < 10; i++) {
        printf("Digite o %d valor: ", i + 1);
        scanf("%d", &v[i]);
    }

    // Ordenação
    mergeSort(v, 0, 9);

    // Exibição do vetor ordenado
    printf("\nVetor ordenado:\n");
    for (i = 0; i < 10; i++) {
        printf("%d ", v[i]);
    }

    // Menor e maior número
    menor = v[0];
    maior = v[9];

    // Contagem das ocorrências
    for (i = 0; i < 10; i++) {
        if (v[i] == menor) {
            contMenor++;
        }
        if (v[i] == maior) {
            contMaior++;
        }
    }

    printf("\n\nMenor numero: %d", menor);
    printf("\nQuantidade de vezes que aparece: %d", contMenor);

    printf("\n\nMaior numero: %d", maior);
    printf("\nQuantidade de vezes que aparece: %d\n", contMaior);

    return 0;
}
