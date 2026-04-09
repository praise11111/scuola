/*data una stringa e il fattore di cifratura cifrare una stringa di 3 
*/


void calcola(char *s, int fatt){
    int dim=strlen(s);
    for(int i=0;i<dim;i++){
        s[i]=s[i]+fatt;
        if(s[i]==122){
            s[i]=s[i]-23;
            }else if(s[i]==121){
                s[i]=s[i]-23;
                    }else if(s[i]==120){
                        s[i]=s[i]-23;
                    }

    }
}
#include <stdio.h>
#include <string.h>
int main(){
char s[100];
int fatt;
printf("fattore di cifratura");
scanf("%d",&fatt);
printf("inserisci una parola/frase");
scanf("%c", &s);
calcola(s,fatt);
printf("la stringa cifrata e': %s", s);
}