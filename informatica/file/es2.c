/*inserite le informazioni di studenti:
nome-eta-media voti scolastici
determinare lo studente con la media piu alta
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Studente{
    char nome[50];
    int eta;
    float media;
}Studente;

void scriveStudenti(char *nome_file,int n_studenti){
    FILE *f=fopen(nome_file,"ab");
    if(f==NULL){
        printf("errore nell'apertura ");
        exit(1);
    }
    for(int i=0;i<n_studenti;i++){
        Studente s;
        printf("inserisci il nome studente %d", i+1);
        scanf("%49", s.nome);
        getchar();
        printf("inserisci eta studente %d", i+1);
        scanf("%49", s.eta);
        printf("inserisci media voti studente %d", i+1);
        scanf("%49", s.media);
        getchar();
        //scrivere dei dati in file finario
        fwrite(&s,sizeof(Studente),1,f);
    }
    fclose(f);
    if(ferror(f)){
        printf("errore nella chiusura ");
        exit(1);
    }
}

Studente* leggiStudenti(char *nome_file,Studente *array){
    FILE* f=fopen(nome_file,"rb");
    if(f==NULL){
        printf("errore nell'apertura ");
        exit(1);
    }
    int i=0;
    array=(Studente*)realloc(array,sizeof(Studente));
    if(array==NULL){
        printf("errore di allocazione");
        exit(1);
    }
    while(fread(&array[i],sizeof(Studente),1,f)!=0){
        i++;
        array=(Studente*)realloc(array,sizeof(Studente));
        if(array==NULL){
        printf("errore di allocazione");
        exit(1);
    }
    }
    array=(Studente*)realloc(array,i*sizeof(Studente));
    if(array==NULL){
        printf("errore di allocazione");
        exit(1);
    }
    fclose(f);
    if(ferror(f)){
        printf("errore nella chiusura ");
        exit(1);
    }
    return array;
}

Studente trova_migliore(Studente *array){
    int dim=sizeof(array)/sizeof(Studente);
    Studente best={"",0,0};

    for(int i=0;i<dim;i++){
        if(array[i].media>best.media){
            best.media=array[i].media;
            best.eta=array[i].eta;
            strcpy(best.nome,array[i].nome);
        }
    }
    return best;
}

int main(){
    int n_studenti;
    char nome_file[50];

    printf("inserisci il nome del file: ");
    scanf("%49", nome_file);
    printf("inserisci il numero di studenti: ");
    scanf("%d", &n_studenti);

    scriveStudenti(nome_file,n_studenti);
    Studente *array=NULL;
    array=leggiStudenti(nome_file,array);
    Studente best=trova_migliore(array);
    
    printf("lo studente con la media piu alta e': %s con media %.2f", best.nome, best.media);
    free(array);
    return 0;
}