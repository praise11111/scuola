/*Scrivere un programma in C che gestisca un insieme di numeri interi usando un array dinamico.
Il programma deve permettere, tramite menù:
    1. Aggiungere un numero (espandendo l’array con realloc)
    2. Visualizzare tutti i numeri
    3. Cercare un numero specifico
    4. Ordinare i numeri in ordine crescente
    5. Eliminare un numero scelto
    6. Uscire
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int *numeri=NULL; //dichiaro un array dinamico
    int dimensione=0; //dichiaro quanti elementi ci sono
    int scelta, i, n, trovato=0;
    
    do{
        printf("\n----MENU----\n");
        printf("1. Aggiungere un numero (espandendo l’array con realloc)\n");
        printf("2.  tutti i numeri\n");
        printf("3. Cercare un numero specifico\n");
        printf("4. Ordinare i numeri in ordine crescente\n");
        printf("5. Eliminare un numero scelto\n");
        printf("6. Uscire\n");
        printf("esegui una scelta: ");
        scanf("%d", &scelta);

        switch(scelta){
            case 1:
                printf("numero da inserire");
                scanf("%d", &n);
                numeri=(int*)realloc(numeri, (dimensione+1)*sizeoff(int));
                if(numeri=NULL){
                    printf("errore di allocazione\n");
                    return 1;
                }
                numeri[dimensione]=n;
                dimensione++;
                printf("numero aggiunto\n");
            break;
            case 2:
                printf("contenuto dell'array: ");
                if(dimensione==0)
                    printf("array vuoto");
                else
                    for(i=0;i<dimensione;i++){
                    printf("%d", numeri[i]);
                    }
            break;
            case 3:
                    printf("numero da cercare: ");
                    scanf(%"%d", &n);
                    for(i=0;i<dimensione;i++){
                        if(numeri[i]==n){
                            trovato=1;
                            printf("numero trovato in posizione %d", i);
                        }

                    }
                    if(trovato==0){
                        printf("elemento non trovato\n");
                    }
            break;
            default;
        }
    }while(scelta !=6);
}