/*dichiarare un array di LIBRI. 

Consentire l'inserimento dei dati di un libro che prevede le seguenti informazioni: 
titolo,autore.isbn.copie_totali,copie_disponibili,data_prestito e data_restituzione.

aggiornare correttamente il numero di copie disponibili.
Registrare il prestito di un libro:
	-inserendo la data di un prestito e la data di restituzione;
	-decrementando il numero di copie disponibili;
	-impedendo il prestito se non ci sono copie disponibili;
	
Visualizzare l'elenco completo dei libri con tutte le informazioni .
Visualizzare solo i libri attualmente in prestito(copie disponibili<copie totali).
Cercare un libro tramite ISBN.
Stampare solo i libri con prestito scaduto.

Accedere ai campi delle date tramite struct annidata
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    int giorno[2];
    int mese[2];
    int anno[4];
} Data;

struct Libro{
	char titolo[50];
	char autore[50];
	int copie_totali[50];
	int copie_disponibili[50];
	int isbn[5];
	Data data_prestito;
    Data data_restituzione;
};

Libro libri[100];
int num_libri = 0;

void inserisciLibro(Libro *libri){
	Libro nuovolibro;
    printf("Inserisci titolo:");
    fgets(nuovolibro->titolo, sizeof(nuovolibro->titolo), stdin);
    printf("Inserisci autore:");
    fgets(nuovolibro->autore, sizeof(nuovolibro->autore), stdin);
    printf("Inserisci copie totali:");
    scanf("%d", &nuovolibro->copie_totali);
    printf("Inserisci copie_disponibili:");
    scanf("%d", &nuovolibro->copie_disponibili);
    printf("numero totale di copie:");
    scanf("%d", &nuovolibro->copie_totali);
    printf("inserisci isbn del libro:");
    scanf("%d", &nuovolibro->isbn);
    libri[num_libri++]=nuovoLibro;
}

int cercaLibroISBN(Libro *libri,int isbnl){
    for(i=0;i<num_libri;i++){
        if(strcmp(libri[i]->isbn,isbnl)== 0){
            return i;
        }
    }
    return -1; 
}

void prestito(Libro *libri){
    printf("ISBN libro prestare:");
    scanf("%d", isbn);
    
    int libreriapraise=cercaLibroISBN(isbn);
    if(libreriapraise==-1){
        printf("libro inesistente");
    }
    
    if(libri[libreriapraise]->copie_disponibili==0){
        printf("nessuna copia disponibile");
    }

    
    printf("Inserisci data prestito:");
    scanf("%d",&libri[libreriapraise]->data_prestito.giorno);
    scanf("%d",&libri[libreriapraise]->data_prestito.mese);
    scanf("%d",&libri[libreriapraise]->data_prestito.anno);
    printf("Inserisci data restituzione:");
    scanf("%d",&libri[libreriapraise]->data_restituzione.giorno);
    scanf("%d",&libri[libreriapraise]->data_restituzione.mese);
    scanf("%d",&libri[libreriapraise]->data_restituzione.anno);
    libri[libreriapraise]->copie_disponibili--;
}

void visualizzalibri(Libro *libri){
    for(i=0;i<num_libri;i++){
        printf("titolo: %s",libri[i]->titolo);
        printf("autore: %s",libri[i]->autore);
        printf("ISBN: %s",libri[i]->isbn);
        printf("copie totali: %d",libri[i]->copie_totali);
        printf("copie disponibili: %d",libri[i]->copie_disponibili);
        if(libri[i]->copie_disponibili<libri[i]->copie_totali){
            printf("in prestito");
        } else {
            printf("disponibile");
        }
        if(libri[i]->data_prestito->giorno!=0){
            printf("data prestito: %d/%d/%d", libri[i]->data_prestito->giorno,libri[i]->data_prestito->mese,libri[i]->data_prestito->anno);
        }
        if(libri[i]->data_restituzione->giorno!=0){
            printf("data restituzione: %d/%d/%d", libri[i]->data_restituzione->giorno,libri[i]->data_restituzione->mese,libri[i]->data_restituzione->anno);
        }
    }
}

void visualizzainprestito(Libro *libri){
    printf("in prestito:");
    for(i=0;i<num_libri;i++){
        if(libri[i]->copie_disponibili<libri[i]->copie_totali){
            printf("titolo: %s, ISBN: %s",libri[i]->titolo,libri[i]->isbn);
        }
    }
}


int main(){
	struct Libro libri;
	int i;
	int isbnl;
	
	int scelta;
    do {
        printf("1. Inserisci libro\n");
        printf("2. Visualizza libri\n");
        printf("3. prestito\n");
        printf("4. visualizza libri in prestito\n");
        printf("5. cerca libro con isbn\n");
        printf("0. Esci\n");
        printf("Scelta: ");
        scanf("%d", &scelta);
        while((c= getchar())!='\n'){}

        switch (scelta){
            case 1:
                inserisciLibro(&libri);
            case 2:
            	visualizzalibri(&libri);
            case 5:
                printf("inserisci isbn del libro che vuoi cercare:");
                scanf("%d",isbnl);
                cercalibroISBN(&libri,isbnl);
            case 3:
            	prestito(&libri);
            case 4:
            	visualizzainprestito(&libri);
            case 0:
                printf("exit\n");
                break;
            default:
                printf("Scelta non valida!\n");
        } 
    } while(scelta!=0);

}
