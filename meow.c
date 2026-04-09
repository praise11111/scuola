/*data una stringa trovare una sottostringa utilizzando le funzioni senza utilizzare la libreria string.h*/
#include <stdio.h>
#define max 100
int dim(char str[]){
    int dim=0;
    while(str[dim]!='\0'){
        dim++;
    }
    return dim;
}
int main(){
    char stringa[max], sottostringa[max];
    int dim1=dim(stringa);
    int dim2=dim(sottostringa);
    printf("inserisci una stringa:");
    fgets(stringa, max, stdin);
    printf("inserisci una sottostringa da cercare:");
    fgets(sottostringa, max, stdin);
    for (int i=0;i<=dim1;i++){
        for(int j=0;j<dim2;j++){
            if(stringa[i]==sottostringa[j])