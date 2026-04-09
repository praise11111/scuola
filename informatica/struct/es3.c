/*visualizzare le squadre il cui allenatore presenta piu di 
10 titoli e un punteggio della squadra superiore a 30
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct squadra{
    char nome[20];
    char colore[20];
    int punteggio;
    struct allenatore{
        char nomeAl[20];
        char cognome[20];
        int titoli;
    }mister;
};
typedef struct squadra squadre;

void inserisci_info(squadre *team, int n){
    for(int i = 0; i < n; i++){
        printf("squadra %d:", i+1);
        printf("nome squadra: ");
        scanf("%s", team[i].nome);
        printf("colore: ");
        scanf("%s", team[i].colore);
        printf("punteggio: ");
        scanf("%d", &team[i].punteggio);
        printf("nome allenatore: ");
        scanf("%s", team[i].mister.nomeAl);
        printf("cognome allenatore: ");
        scanf("%s", team[i].mister.cognome);
        printf("titoli allenatore: ");
        scanf("%d", &team[i].mister.titoli);
    }
}

int main(){
    int n;
    printf("Quante squadre vuoi inserire? ");
    scanf("%d", &n);
    int trovate = 0;
    
    squadre *team = (squadre*)malloc(n * sizeof(squadre));
    inserisci_info(team, n);
    
    printf("squadre con allenatore come mourinho");
    
    for(int i = 0; i < n; i++){
        if(team[i].mister.titoli > 10 && team[i].punteggio > 30){
            printf("squadra: %s", team[i].nome);
            printf("colore: %s", team[i].colore);
            printf("punteggio: %d", team[i].punteggio);
            printf("allenatore: %s %s", team[i].mister.nomeAl, team[i].mister.cognome);
            printf("titoli: %d", team[i].mister.titoli);
            trovate++;
        }
    }
    
    if(trovate == 0){
        printf("le squadre fanno schifo");
    }
    
    free(team);
    return 0;
}
