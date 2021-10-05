/*Nome: Victor Akio Domoto  */
/*AED1 - UNIFESP            */

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
    char Frase;
    Apontador Prox;
    } TDados;
    
typedef struct {
    Apontador first, last;
    int Tamanho;
} TLista;


void TLista_Start(TLista *Lista){
    Lista->first = (Apontador) malloc(sizeof(TDados));
    Lista->last = Lista->first;
    Lista->first->Prox = NULL;
    Lista->Tamanho = 0;
}

//Lista vazia
int TLista_void(TLista *Lista){
    return (Lista->first == Lista->last);
}
//Tamanho da lista
int TLista_tam(TLista *Lista){
    return (Lista->Tamanho);
}


//Insere novo elemento na lista
int TLista_adiciona(TLista *Lista, Apontador a, char Frase){
    Apontador ant, nov;
    ant = Lista->first;
    while ((ant != Lista->last) && (ant->Prox != a))
    ant = ant->Prox;
    if (ant->Prox != a)
        return 0;
    nov = (Apontador) malloc(sizeof(TDados));
    nov->Frase = Frase;
    nov->Prox = ant->Prox;
    ant->Prox = nov;
    if (ant == Lista->last)
        Lista->last = nov;
    Lista->Tamanho++;
    return 1;
}

//Retira elemento da lista
int TLista_remove(TLista *Lista, Apontador p, char *Frase){
    Apontador ant, aux;
    ant = Lista->first;
    while ((ant != Lista->last) && (ant->Prox != p))
        ant = ant->Prox;
    if (ant->Prox != p)
        return 0;
    aux = ant->Prox;
    ant->Prox = aux->Prox;
    if (aux == Lista->last)
        Lista->last = ant;
    *Frase = aux->Frase;
    free(aux);
    Lista->Tamanho--;
    return 1;
}

//retorna
Apontador TLista_return(TLista *Lista, int p){
    Apontador apont;
    int cont;

    cont = 0;
    apont = Lista->first->Prox;
    while ((apont != NULL) && (cont != p)) {
        apont = apont->Prox;
    cont++;
}

return apont;
}


void imprime(TLista lista, char letra){
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

  TLista lista;         //criando TLista
  TLista_Start(&lista); //inicia lista

  gets(texto);  
  quant = strlen(texto);

    //quantas vezes os erros se repetem 
  int repeticao;
  
  for(i = 0; i < quant; i++) {
    switch(texto[i]) {
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
        TLista_adiciona(&lista, TLista_return(&lista, cont), texto[i]);
        cont++;
        break;
    } 
  } 

imprime (lista, letra); //funcao para imprimir monitor
  
}