/*verificare se una stringa è palindroma
    es: anna è palindroma
        ciao non è palindroma 
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char* string;
int lunghezza(string s){
    int i=0;
    while(s[i]!='\0'){
        i++;
    }
    return i-1;
}

int Palindroma(string s,int len){
    int flag=0,i,j;
    for(i=0,j=len-1;i<len/2;i++,j--){
        if(s[i]!=s[j])
            flag=1;
        }
        return flag;
}

int main(){
    int dim=0,palindroma=0;

    string s=(string)malloc(50*sizeof(char));
    if(s==NULL) return 1;

    printf("inserisci una stringa: " );
    fgets(s,50,stdin);
    printf("\n%s", s);
    dim=lunghezza(s);
    printf("\n%d", dim);
    palindroma=Palindroma(s,dim);
    if(palindroma==1)
        printf("\nla frase non è palindroma");
    else
        printf("\nla frase è palindroma");
}