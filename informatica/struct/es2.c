/* creare  una struct  squadra contenente le seguenti informazioni : nome,colore,punteggio.
caricato un massimo di 10 squadre stampare quelle con punteggio superiore a 100
*/

#include <stdio.h>
#include <stdlib.h> 

void clear_buffer(){
    int c;
    while((c=getchar())!='\n'){}
}
typedef struct {
    char nome[30];
    char colore[20];
    int punteggio;
}Squadra;

void stampa(Squadra *teams, int n){
    printf("Squadre con punteggio superiore a 100:\n");
    for(int i=0;i<n;i++){
        if(teams[i].punteggio>100){
            printf("Nome: %s, Colore: %s, Punteggio: %d\n", teams[i].nome, teams[i].colore, teams[i].punteggio);
        }
    }
}

int main(){
    Squadra *teams;
    int n;

    do{
        printf("inserisci il numero delle squadre (max10): ");
        scanf("%d", &n);
    }while(n<0 || n>10);

    teams=(Squadra*)malloc(sizeof(Squadra));
    if(teams==NULL){
        printf("Errore di allocazione");
        return 1;
    }
    for(int i=0;i<n;i++){
        printf("inserisci il nome della squadra: ");
        scanf("%s", teams[i].nome);
        clear_buffer();
        printf("inserisci il colore della squadra: ");
        scanf("%s", teams[i].colore);
        clear_buffer();
        printf("inserisci il punteggio della squadra: ");
        scanf("%d", &teams[i].punteggio);
        clear_buffer();
    }
   
}