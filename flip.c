/*data una stringa riscrivere la stringa all'inverso scambiando gli elementi 
*/
#include <stdio.h>
#include <string.h>
#define max 100
int main(){
    char stringa[max];
    int dim = strlen(stringa);
    int i;
    char temp = stringa[i];
    printf("inserisci una stringa: ");
    fgets(stringa, max, stdin);
    for(i = 0; i < dim / 2; i++){
        stringa[i] = stringa[dim - i - 1];
        stringa[dim - i - 1] = temp;
    }
    printf("stringa invertita: %s\n", stringa);
}
