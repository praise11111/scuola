#include <stdio.h>

// Funzione per scambiare due numeri
void scambia(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Selection Sort con nomi chiari
void selectionSort(int array[], int dim) {
    int posizioneMinimo;

    for (int i = 0; i < dim - 1; i++) {
        posizioneMinimo = i;

        for (int j = i + 1; j < dim; j++) {
            if (array[j] < array[posizioneMinimo]) {
                posizioneMinimo = j;
            }
        }

        if (posizioneMinimo != i) {
            scambia(&array[i], &array[posizioneMinimo]);
        }
    }
}

int main() {
    int numeri[100];
    int dim;

    printf("Quanti numeri vuoi inserire (max 100)? ");
    scanf("%d", &dim);

    if (dim <= 0 || dim > 100) {
        printf("Numero non valido.\n");
        return 1;
    }

    printf("Inserisci %d numeri:\n", dim);
    for (int i = 0; i < dim; i++) {
        scanf("%d", &numeri[i]);
    }

    selectionSort(numeri, dim);

    printf("Numeri ordinati:\n");
    for (int i = 0; i < dim; i++) {
        printf("%d ", numeri[i]);
    }
    printf("\n");

    return 0;
}
