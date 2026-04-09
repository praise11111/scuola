/* classe di studenti:
cognome,nome,classe,matricola
per goni studente dotato di matricola abbiamo 
le informazioni riguardante gli esami e il livello raggiunto
1) riceracre lo studente con piu certificazioni 
*/
typedef struct {
    char cognome[20];
    char nome[20];
    char classe[3];
    int matricola; //(1000-9999)
}Studente;  

typedef struct{
    int matricola;
    char corso[20];
    int livello; //(1-3)
} certificazioni;

#include <stdio.h>
#include <stdlib.h>
void clear_buffer(){
    int c;
    while((c=getchar())!='\n'){}
}
int main(){
    Studente *students;
    certificazioni *certif;
    int n,m;
    do{
        printf("inserisci il numero degli studenti: ");
        scanf("%d", &n);
    }while(n<=0);   
    students=(Studente*)malloc(sizeof(Studente)*n);
    if(students==NULL){
        printf("Errore di allocazione");
        return 1;
    }
    for(int i=0;i<n;i++){
        printf("inserisci il cognome dello studente: ");
        scanf("%s", students[i].cognome);
        clear_buffer();
        printf("inserisci il nome dello studente: ");
        scanf("%s", students[i].nome);
        clear_buffer();
        printf("inserisci la classe dello studente: ");
        scanf("%s", students[i].classe);
        clear_buffer();
        printf("inserisci la matricola dello studente (1000-9999): ");
        scanf("%d", &students[i].matricola);
        clear_buffer();
    }
    do{
        printf("inserisci il numero delle certificazioni: ");
        scanf("%d", &m);
    }while(m<=0);
    certif=(certificazioni*)malloc(sizeof(certificazioni)*m);
    if(certif==NULL){
        printf("Errore di allocazione");
        return 1;
    }
    for(int i=0;i<m;i++){
        printf("inserisci la matricola dello studente: ");
        scanf("%d", &certif[i].matricola);
        clear_buffer();
        printf("inserisci il corso della certificazione: ");
        scanf("%s", certif[i].corso);
        clear_buffer();
        printf("inserisci il livello della certificazione (1-3): ");
        scanf("%d", &certif[i].livello);
        clear_buffer();
    }
    //ricerca studente con piu certificazioni
    int max_cert=0;
    int studente_max=-1;
    for(int i=0;i<n;i++){
        int count=0;
        for(int j=0;j<m;j++){
            if(students[i].matricola==certif[j].matricola){
                count++;
            }
        }
        if(count>max_cert){
            max_cert=count;
            studente_max=i;
        }
    }
    if(studente_max!=-1){
        printf("Lo studente con piu certificazioni e': %s %s con %d certificazioni.\n", students[studente_max].nome, students[studente_max].cognome, max_cert);
    }else{
        printf("Nessuno studente ha certificazioni.\n");
    }
    free(students);
    free(certif);
    return 0;
}
