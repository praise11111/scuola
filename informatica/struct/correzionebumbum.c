#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct data{
    int giorno;
    int mese;
    int anno;
}data;

typedef struct libro{
    char titolo[20];
    char autore[20];
    int isbn;
    int copie_totali;
    int copie_disponibili;
    data data_prestito;
    data data_restituzione;
}libro;

libro*inseriscilibro(libro* l,int* n){
    l=(libro*)realloc(l,((*n)+1)*sizeof(libro));
    if(l==NULL){
        printf("errore di allocazione\n");
        exit(1);
    }
    printf("inserisci il titolo:");
    fgets(l[*n].titolo,100,stdin);
    l[*n].titolo[strcspn(l[*n].titolo;"\n")]='\0';

}

printf("inserisci autore:");
    fgets(l[*n].);
    
    printf("inserisci isbn: ");
    scanf("%d", );

void stampa(libro *l,int n){
    int i;
    for(i=0;i<n;i++){
        printf("\ntitolo: %s",l[i].titolo);
        printf("\nautore: %s",l[i].autore);
        printf("\nisbn: %d",l[i].isbn);
        printf("\ncopie totali: %d",l[i].copie_totali);
        printf("\ncopie disponibili: %d", l[i].copie_disponibili);
        printf("\ndata prestito: %d/%d/%d", l[i].data_prestito.giorno,l[i].data_prestito.mese,l[i].data_prestito.anno);
        printf("\ndata restituzione: %d/%d/%d", l[i].data_restituzione.giorno,l[i].data_restituzione.mese,l[i].data_restituzione.anno);
    }
}

void resgistralibro(libro *l,int n){
    int isbn,trovato=0;
    int i;

    printf("inserisci il codice isbn del libro che stai cercando: ");
    scanf("%d",)
}

int main(){
    libro*biblioteca=NULL;
    int n=0, scelta;
    char c;

    do{
        printf("\n--MENU--\n");
        printf("1.inserisci nuovo libro\n");
        printf("2.visualizza tutti i libri\n");
        printf("3.registra prestito\n");
        printf("4.cerca libro per ISBN\n");
        printf("5.visualizza libri in prestito\n");
        printf("6.stampare il libro con il prestito scaduto\n");
        printf("0.esci\n");
        printf("scelta: ");
        scanf("%d", &scelta);
        while((c=getchar())!= '\n'){}

        switch(scelta){
            case 0:
                printf("esci dal programma\n");
                break;
            case 1:
                biblioteca=inseriscilibro(biblioteca,&n);
                break;
            case 2:{
                stampa(biblioteca,n);
                break;
            }
            case 3:{
                printf("")
            }
        }
    }while(scelta!=0);

}