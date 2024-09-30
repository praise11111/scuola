/*DATI DUE NUMERI A e B VERIFICARE
    SE A è IL QUADRATO DI B     */

    #include <stdio.h>
    int main(){
        float A=0;
        float B=0;
        float quadrato=0;

        printf("inserisci il primo valore: ");
        scanf("%f" , &A);
        printf("inserisci il secondo valore: ");
        scanf("%f" , &B);

        quadrato = B*B;
        printf("il doppio è: %f" , quadrato);

        if(A== quadrato){
            printf("il primo valore %f corrisponde al quadrato del secondo %f" , A,B);
        }
        else{
            printf("il primo valore %f non corrisponde al quadrato del secondo %f" , A,B);
        }

 }