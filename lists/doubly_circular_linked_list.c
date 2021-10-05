/*Nome: Victor Akio Domoto  */
/*AEDI - UNIFESP            */
#define max 50000
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef int TCod;
typedef struct {
    char frase[max];
    } TItem;

typedef struct Dados *Apontador;

typedef struct Dados {
    char Item;
    Apontador ant, prox;
    } TDados;

typedef struct {
    Apontador last;
    int Tamanho;
} TLista;

//Starta a lista
void TLista_Start(TLista *Lista){
    Lista->last = (Apontador) malloc(sizeof(TDados));
    Lista->last->prox = Lista->last;
    Lista->last->ant = Lista->last;
    Lista->Tamanho = 0;
}
//verifica se a lista esta vazia
int TLista_void(TLista *Lista){
    return (Lista->last->prox == Lista->last);
}
int TLista_tam(TLista *Lista){
    return (Lista->Tamanho);
}

//Inserir na lsita
int TLista_Adiciona(TLista *Lista, Apontador p, char frase){
    Apontador nov;
    if (p == NULL)
        return 0;
    nov = (Apontador) malloc(sizeof(TDados));
    nov->Item = frase;
    nov->prox = p;
    nov->ant = p->ant;
    p->ant->prox = nov;
    if (p->ant == Lista->last)
        Lista->last = nov;
    p->ant = nov;
    Lista->Tamanho++;
    return 1;
}

//retirar da lista
int TLista_remove(TLista *Lista, Apontador p, char *frase){
    Apontador aux;
    if (TLista_void(Lista))
        return 0;
    aux = p;
    p->ant->prox = p->prox;
    p->prox->ant = p->ant;
    if (aux == Lista->last)
        Lista->last = p->ant;
    *frase = aux->Item;
    free(aux);
    Lista->Tamanho--;
    return 1;
}

// return
Apontador TLista_return(TLista *Lista, int p){
    Apontador apont;
    int cont;

    cont = 0;
    apont = Lista->last->prox->prox; 
    while ((apont != Lista->last->prox) && (cont != p)){
        apont = apont->prox;
        cont++;
}

    return apont;
}

void imprime_lista(TLista lista, char letra){
      while(!TLista_void(&lista)) {  
    TLista_remove(&lista, TLista_return(&lista, 0), &letra);
    printf("%c", letra);
  }
}


//funcao principal
int main (void) {
  //declaracao de variaveis  
  int i, quant, cont;
  char texto[max], letra;

  //valores iniciais
  i=0;
  quant=i;
  cont=quant;
  int j;

  TLista lista;         //criando TLista
  TLista_Start(&lista); //inicia lista

  gets(texto);  
  quant = strlen(texto);  //Tamanho do texto

  //quantas vezes os erros se repetem 
  int repeticao;
  

    for(j = 0; j < quant; j++) {
    switch(texto[j]) {
      case '[':
        cont = 0;
      break;

      case ']':
        cont = lista.Tamanho;
      break;

      case '-': 
        if(cont > 0) {
          cont--;
          TLista_remove(&lista, TLista_return(&lista, cont), &letra);
        }
      break;

      case '<':
        if(cont > 0) {
          cont--;
        }
      break;

      case '>':
        if(cont < lista.Tamanho) {
          cont++;
        }
      break;

      default:
        TLista_Adiciona(&lista, TLista_return(&lista, cont), texto[j]);
        cont++;
      break;
    }
    } 

imprime_lista (lista, letra); //funcao para imprimir monitor

}