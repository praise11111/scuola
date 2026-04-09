/*Il codice fiscale è un codice alfanumerico di 16 caratteri che serve per identificare in modo univoco ogni cittadino italiano.
È composto in questo modo:
CCC NNN YYMDD LLLL C
dove:
CCC → prime tre lettere del cognome, formate prendendo le consonanti (o le vocali, se le consonanti non bastano);
NNN → prime tre lettere del nome, con una regola simile a quella del cognome (ma se ci sono quattro consonanti, si prendono la 1ª, 3ª e 4ª);
YY → ultime due cifre dell’anno di nascita;
M → lettera che rappresenta il mese di nascita (A = gennaio, B = febbraio, C = marzo, D = aprile, E = maggio, H = giugno, L = luglio, M = agosto, P = settembre, R = ottobre, S = novembre, T = dicembre);
DD → giorno di nascita (per le donne si aggiunge 40 al giorno);
LLLL → codice del comune di nascita (per questo esercizio useremo G186, che è il codice del comune di Ostiglia);
C → lettera di controllo calcolata con una formula basata sui precedenti 15 caratteri.
Scrivere un programma in linguaggio C che calcoli e visualizzi il codice fiscale (senza il carattere di controllo finale) chiedendo all’utente di inserire nome, cognome, data di nascita nel formato GG/MM/AAAA, sesso (M o F).
Sarà necessario verificare la correttezza degli input, quindi nome e cognome devono essere composti solo da lettere; la data deve essere composta solo da numeri (oltre agli eventuali /, si può scegliere se far inserire un valore della data alla volta o tutta la data con il separatore /); il sesso può avere solo la lettera M o F.
 Per il controllo di nome, cognome e data, si suggerisce di leggere l’input carattere per carattere usando getchar().
*/

#include <stdio.h>
#include <string.h>

int consonanti(char* cognome){
    int cnt=0;
    for(int i=0; cognome[i] != '\0'; i++){
     strchr("BCDFGHJKLMNPQRSTVWXYZbcdfghjklmnpqrstvwxyz", cognome[i]);
        cnt++;
        if(cnt==3){
            return 1;
        }
    }
    
}

 int main(){
    char nome[20], cognome[20], sesso[3], data[11];
    char comune[5];
    printf("inserisci nome, cognome, data di nascita, sesso il comune deve essere G186\n");
    scanf("%s %s %s %s %s", nome, cognome, data, sesso, comune);
    strcat(nome, cognome); 
    strcat(nome, data);
    if(strcmp(sesso, "F") == 0){
        strcpy(sesso, "40");
        strcat(nome, sesso);
    }
    strcat(nome, comune); 
    printf("il codice fiscale e': %s\n", nome);
 }