/*Scrivere un programma in linguaggio C che:
    1. Allochi dinamicamente un array iniziale di n numeri interi con malloc;
    2. inserimento dei valori;
    3. stampi l'array;
    4. calcoli la somma dei valori multipli di 3;
    5. creiamo un nuovo array con solo i numeri dispari
*/

#include <stdio.h>
#include <stdlib.h>

    int* creaVett(int _n){
        int*vettore=(int*)malloc((_n)*sizeof(int));
        if(vettore==NULL){
            printf("errore di allocazione\n");
            return NULL;
        }
        return vettore;
    }
    int* inserisciValori (int* _vettore, int _n){
        for(int i=0;i<_n;i++){
            printf("inserisci l'elemento: ");
            scanf("%d", &_vettore[i]);
        }
        return _vettore;
    }
    void stampaVett(int *_vettore, int N){
        for(int i=0;i<N;i++){
            printf("%d", _vettore[i]);
            printf("\n");
        }
    }
    int calcolaSomma(int *_vettore,int _n){
        int somma=0;
        for(int i=0;i<_n;i++){
            if(_vettore[i]%3==0)
                somma+=_vettore[i];
        }
        return somma;
    }
    int estraiDispari(int *_vettore, int _n,int *_dimDispari){
        int *_dispari=NULL;
        *_dimDispari=0;
        for(int i=0;i<_n;i++){
            if(_vettore[i]%2!=0){
                (*_dimDispari)++;
                int *tmp=realloc(_dispari,(*_dimDispari)*sizeof(int));
                if(tmp==NULL){
                    printf("errore di allocazione\n");
                    free(_dispari);
                    return NULL;
                }
                _dispari=tmp;
                _dispari[(*_dimDispari)-1]=_vettore[i];
            }
        }
        return _dispari;
    }
int main(){
    int *vettore=NULL;
    int *dispari=NULL;
    int dimDispari;
    int n;
    do{
        printf("inserisci la quantita degli elementi: ");
        scanf("%d", &n);
    }while(n<0);

    vettore=creaVett(n);
    vettore=inserisciValori(vettore,n);
    stampaVett=(vettore,n);
    printf("la somma degli elementi divisibili per 3 sono: %d\n", calcolaSomma(vettore,n));
    dispari=estraiDispari(vettore,n,&dimDispari);
    printf("l'array contenente gli elementi dispari risulta: ");
    stampaVett(dispari,dimDispari);
    free(vettore);
    free(dispari);
}