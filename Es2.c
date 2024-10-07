#include <stdio.h>
int main(){
  int num1;
  int num2;
  int num3;
  int max;
  int min;
  float media;
  
  printf("Inserisci il primo numero: ");
    scanf("%d", &num1);
    printf("Inserisci il secondo numero: ");
    scanf("%d", &num2);
    printf("Inserisci il terzo numero: ");
    scanf("%d", &num3);
    max = num1;
    if (num2 > max) {
        max = num2;
    }
    if (num3 > max) {
        max = num3;
    }
    min = num1;
    if (num2 < min) {
        min = num2;
    }
    if (num3 < min) {
        min = num3;
    }
    media = (num1 + num2 + num3) / 3.0;
    printf("Il numero più grande è: %d", max);
    printf("Il numero più piccolo è: %d", min);
    printf("La media aritmetica è: %.2f", media);
}

