/* Provare la libreria string.h
per le seguenti operazioni 
1. calcola lunghezza stringa
2. controllare se 2 stringhe sono uguali
3. copiare una stringa 
4. cercare un carattere e comunicare la frequenza
5. concatenare 2 stringe
6. ricerca di una stringa nell'altra 
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
    char str[100];
    char str1[100];
    char c;
    printf("Inserisci il carattere c da cercare: ");
    scanf("%c",&c);
    void clear_buffer(){
    int c;
    while((c=getchar())!='\n'){}
    }
    printf("Inserisci una stringa: ");
    fgets(str,100,stdin);
    int len=strlen(str);
    printf("La lunghezza della stringa è: %d", len);


    int strcmp(str, str1);
    printf("Confronto: %d\n", strcmp(str, str1));

    char *strcpy(str, str1);
    printf("stringa copiata %c\n", strcpy(str, str1));

    char* strchr(str, c);
    printf("Il carattere compare: %c\n", strchr(str, c));

    char *strcat(str, str1);
    printf("Stringa concatenata: %c\n", strcat(str, str1));

    char *strstr(str, str1);
    printf("Stringa in stringa: %c\n", strstr(str, str1));
}
