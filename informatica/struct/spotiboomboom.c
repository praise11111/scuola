
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Canzone {
    int id;
    char titolo[50];
    char artista[50];
    int durata;
    struct Canzone* next;
} Canzone;

typedef struct Lista {
    Canzone* testa;
    int lunghezza;
} Lista;

int id_univoco = 0;

void stampa_canzone(Canzone *c);
void set_canzone(Canzone *c);
Lista* crea_lista();
void stampa_lista(Lista *l);
void inserisci_canzone_lista(Lista *l);
void ricerca_canzone_artista(Lista *l, char* artista);
void libera_memoria(Lista* l);

void inserisci_canzone_playlist(Lista *lista_canzoni, Lista *playlist);
void stampa_playlist(Lista* playlist);
void cancella_canzone_playlist(Lista *playlist);

int main() {
    Lista* lista_canzoni = crea_lista();
    Lista* playlist = crea_lista();

    int scelta;
    char artista[50];

    do {
        printf("\n===== SPOTIFY 0.0.0.1 =====\n");
        printf("1. Inserisci nuova canzone nella lista\n");
        printf("2. Stampa lista canzoni\n");
        printf("3. Cerca canzoni per artista\n");
        printf("4. Aggiungi canzone alla playlist\n");
        printf("5. Stampa playlist\n");
        printf("6. Cancella canzone dalla playlist\n");
        printf("0. Esci\n");
        printf("Scelta: ");
        scanf("%d", &scelta);
        getchar();

        switch (scelta) {
            case 1:
                inserisci_canzone_lista(lista_canzoni);
                break;
            case 2:
                stampa_lista(lista_canzoni);
                break;
            case 3:
                printf("Inserisci artista da cercare: ");
                fgets(artista, 50, stdin);
                ricerca_canzone_artista(lista_canzoni, artista);
                break;
            case 4:
                inserisci_canzone_playlist(lista_canzoni, playlist);
                break;
            case 5:
                stampa_playlist(playlist);
                break;
            case 6:
                cancella_canzone_playlist(playlist);
                break;
            case 0:
                printf("Uscita...\n");
                break;
            default:
                printf("Scelta non valida. Riprova.\n");
        }

    } while (scelta != 0);

    libera_memoria(lista_canzoni);
    libera_memoria(playlist);
    return 0;
}

void stampa_canzone(Canzone *c) {
    printf("ID: %d",c->id);
    printf("Titolo: %s",c->titolo);
    printf("Artista: %s",c->artista);
    printf("Durata: %d secondi",c->durata);
}

void set_canzone(Canzone *c) {
    c->id=id_univoco++;
    printf("titolo canzone:");
    fgets(c->titolo,50,stdin);
    printf("artista canzone:");
    fgets(c->artista, 50, stdin);
    printf("durata canzone:");
    scanf("%d", &c->durata);
}

Lista* crea_lista() {
    Lista* l=(Lista*)malloc(sizeof(Lista));
    l->testa=NULL;
    l->lunghezza=0;
    return l; 
}

void stampa_lista(Lista *l) {
    Canzone* corrente=l->testa;
    while(corrente!=NULL){
        stampa_canzone(corrente);
        corrente=corrente->next;
    }
}

void inserisci_canzone_lista(Lista *l) {
    Canzone* nuova_canzone=(Canzone*)malloc(sizeof(Canzone));
    set_canzone(nuova_canzone);
    nuova_canzone->next=NULL;

    if(l->testa==NULL){
        l->testa=nuova_canzone;
    }else{
        Canzone* corrente=l->testa;
        while(corrente->next!=NULL){
            corrente=corrente->next;
        }
        corrente->next=nuova_canzone;
    }
    l->lunghezza++;
}

void ricerca_canzone_artista(Lista *l, char* artista) {
    Canzone* corrente=l->testa;
    int trovato=0;
    while(corrente!=NULL){
        if(strcmp(corrente->artista, artista)==0){
            stampa_canzone(corrente);
            trovato=1;
        }
        corrente=corrente->next;
    }
}

void libera_memoria(Lista* l) {
    Canzone* corrente=l->testa;
    while(corrente!=NULL){
        Canzone* temp=corrente;
        corrente=corrente->next;
        free(temp);
    }
    free(l);
}

void inserisci_canzone_playlist(Lista *lista_canzoni, Lista *playlist) {
    if(lista_canzoni->testa==NULL){
        printf("Lista canzoni vuota!\n");
        return;
    }
    
    stampa_lista(lista_canzoni);
    printf("Inserisci ID canzone da aggiungere alla playlist: ");
    int id_cercato;
    scanf("%d", &id_cercato);
    getchar();
    
    Canzone* corrente=lista_canzoni->testa;
    while(corrente!=NULL){
        if(corrente->id==id_cercato){
            Canzone* copia=(Canzone*)malloc(sizeof(Canzone));
            copia->id=corrente->id;
            strcpy(copia->titolo, corrente->titolo);
            strcpy(copia->artista, corrente->artista);
            copia->durata=corrente->durata;
            copia->next=NULL;
            
            if(playlist->testa==NULL){
                playlist->testa=copia;
            }else{
                Canzone* temp=playlist->testa;
                while(temp->next!=NULL){
                    temp=temp->next;
                }
                temp->next=copia;
            }
            playlist->lunghezza++;
            printf("Canzone aggiunta alla playlist!\n");
            return;
        }
        corrente=corrente->next;
    }
    printf("Canzone non trovata!\n");
}

void stampa_playlist(Lista* playlist) {
    Canzone* corrente=playlist->testa;
    while(corrente!=NULL){
        stampa_canzone(corrente);
        corrente=corrente->next;
    }
}

void cancella_canzone_playlist(Lista *playlist) {
    if(playlist->testa==NULL){
        printf("Playlist vuota!\n");
        return;
    }
    
    stampa_playlist(playlist);
    printf("Inserisci ID canzone da rimuovere dalla playlist: ");
    int id_cercato;
    scanf("%d", &id_cercato);
    getchar();
    
    if(playlist->testa->id==id_cercato){
        Canzone* temp=playlist->testa;
        playlist->testa=playlist->testa->next;
        free(temp);
        playlist->lunghezza--;
        printf("Canzone rimossa dalla playlist!\n");
        return;
    }
    
    Canzone* corrente=playlist->testa;
    while(corrente->next!=NULL){
        if(corrente->next->id==id_cercato){
            Canzone* temp=corrente->next;
            corrente->next=temp->next;
            free(temp);
            playlist->lunghezza--;
            printf("Canzone rimossa dalla playlist!\n");
            return;
        }
        corrente=corrente->next;
    }
    printf("Canzone non trovata!\n");
}