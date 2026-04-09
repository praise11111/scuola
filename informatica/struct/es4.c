/*registrare le informazioni di alcuni libri titolo,autore,anno pubblicazione.
array di libri
caricare l'array
visualizzare
rimuovere libro 
cercare un libro in base al titolo
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char titolo[50];
    char autore[50];
    char anno_pubblicazione[50];
} Libro;

void caricaLibri(Libro libri[],int *num_libri){
    int n;
    printf("Quanti libri vuoi inserire? ");
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        *num_libri++;
        printf("titolo del libro");
        fgets(libri[*num_libri].titolo,50,stdin);
        printf("Inserisci autore del libro");
        fgets(libri[*num_libri].autore,50,stdin);
        printf("Inserisci anno di pubblicazione del libro");
        fgets(libri[*num_libri].anno_pubblicazione,50,stdin);
    }
}
void visualizzaLibri(Libro libri[],int num_libri){
    for(int i=0;i<num_libri;i++){
        printf("titolo:%s",libri[i].titolo);
        printf("autore:%s",libri[i].autore);
        printf("anno di pubblicazione:%s",libri[i].anno_pubblicazione);
    }
}
int cercaLibro(Libro libri[],int num_libri){
    char titolo_cerca[50];
    printf("libro da cercare:");
    fgets(titolo_cerca,50,stdin);
    for(int i=0;i<num_libri;i++){
        if(strcmp(libri[i].titolo,titolo_cerca)==0){
            return i;
        }
    }
    return 0;
}
void rimuoviLibro(Libro libri[], int *num_libri,char *titolo){
    int indice = cercaLibro(libri, *num_libri, titolo);
    if (indice != -1) {
        for (int i = indice; i < *num_libri - 1; i++) {
            libri[i] = libri[i + 1];
        }
        (*num_libri)--;
        printf("Libro rimosso con successo.\n");
    } else {
        printf("Libro non trovato.\n");
    }
}
int main() {
    Libro libri[50];
    int num_libri=0;
    int scelta;
    do {
        printf("menu:\n");
        printf("marica libri\n");
        printf("visualizza libri\n");
        printf("cerca libro per titolo\n");
        printf("rimuovi libro per titolo\n");
        printf("esci\n");
        scanf("%d", &scelta);
    
        switch(scelta){
            case 1:
                caricaLibri(libri,&num_libri);
                break;
            case 2:
                visualizzaLibri(libri,num_libri);
                break;
            case 3:
                int indice=cercaLibro(libri,num_libri);
                    if(indice!=0){
                        printf("libro trovato:");
                        printf("titolo:%s",libri[indice].titolo);
                        printf("autore:%s",libri[indice].autore);
                        printf("anno di pubblicazione: %s", libri[indice].anno_pubblicazione);
                    } else {
                        printf("Libro non trovato.\n");
                    }
                break;
            case 4:
                printf("Inserisci il titolo del libro da rimuovere: ");
                fgets(titolo_cerca, 50, stdin);
                titolo_cerca[strcspn(titolo_cerca, "\n")] = 0; // rimuovere newline
                rimuoviLibro(libri, &num_libri, titolo_cerca);
                break;
            case 5:
                printf("Uscita dal programma.\n");
                break;
            default:
                printf("Opzione non valida. Riprova.\n");
        }
    } while (scelta != 5);
    return 0;
}

