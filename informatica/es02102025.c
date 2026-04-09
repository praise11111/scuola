/* scrivi un programma in c che:
1.chiede all'utente quanti numeri interi che vuole inserire;
2.alloca dinamicamente un array di quella dimensione con malloc();
3.permette all'utente di inserire i numeri;
4.chiede all'utente se vuole aumentare la dimensione dell'array;
    -se si,richiede la nuova dimensione e usa realloc() per ridimensionarlo;
    -permette quindi di inserire i nuovi valori negli spazi aggiunti;
5.infine,stampa tutti gli elementi dell'array;
*/

#include <stdio.h>
#include <stdlib.h>

int* creaVett(int n){
        int*vettore=(int*)malloc((n)*sizeof(int));
        if(vettore==NULL){
            printf("errore di allocazione\n");
            return NULL;
        }
        return vettore;
    }

int* caricaVett(int* vett, int n){
        for(int i=0;i<n;i++){
            printf("inserisci l'elemento: ");
            scanf("%d", &vett[i]);
        }
        return vett;
    }

int main(){
    int n,*vett=NULL,aum=0;
    char scelta;
    printf("quanti numeri interi vuoi inserire: ");
    scanf("%d", &n);
    creaVett(n);
    vett=caricaVett(vett,n);
    printf("vuoi aumentare la dimensione dell'array? s per si, n per no");
    scanf("%c", &scelta);

    switch(scelta){
    case 's':
        
            printf("di quanto vuoi aumentare la dimensione?");
            scanf("%d", &aum);
            vett=(int*)realloc(vett,(n+aum)*sizeof(int));
            if(vett=NULL){
                printf("errore di allocazione\n");
                return 1;
            }
            for(int i=n;i<aum;i++){
                printf("inserisci il valore:");
                scanf("%d", &vett[i]);
            }
        
        break;
    case 'n':
            for(int i=0;i<n;i++){
                printf("%d", vett[i]);
            }
        
    default:
        break;
    }

}
