/*Nome: Victor Akio Domoto  */
/* AEDII - UNIFESP          */
/* Atividade 14 - judge     */

#include <stdio.h>
#include <stdlib.h>
#define max 100000


typedef struct no{
    int chave;
    struct no *proximo;
}no;


typedef struct{
    no *list;
    int height;
}TABELAHASH;



/* Iniciando a lista    */
void startList(TABELAHASH *lista){
    lista->list = NULL;
    lista->height = 0;
}

/*Iniciando a tabela HASH */
void startHASH(TABELAHASH lista[], int tamanho){
    int i;
    for (i=0; i<tamanho; i++){
        startList(&lista[i]);
    }
}

/* Funcao que ira espalhar a tabela */
int functionHASH(int num, int tam){
    return num % tam;
}

/* Inserindo na lista */
void insertionList(TABELAHASH *lista, int valor, int num){
    no *novo = malloc (sizeof(no));
    if (novo){
       novo->chave = valor;
       novo->proximo = lista->list;
       lista->list = novo;
       lista->height++;
    }
}

/*inserindo na tabela */
void insertionHASH(TABELAHASH lista[], int valor, int tam){
    int localizacao = functionHASH(valor, tam);
    insertionList(&lista[localizacao], valor, tam);
}


int searchList(TABELAHASH *lista, int chave){
    no *sec = lista->list;
    while (sec && sec->chave!=chave){
        sec = sec->proximo;
    }
    if (sec)
        return 1;
    return 0;
}


int searchHASH(TABELAHASH lista[], int chave, int tamanho){
    int localizacao = functionHASH(chave, tamanho);
    return searchList(&lista[localizacao], chave);
}





void showList(TABELAHASH *lista){
    no *sec = lista->list;
    while (sec && sec->chave!=NULL){
        printf("%d ", sec->chave);
        sec = sec->proximo;
    }
    printf("\n");
}

void showHASH(TABELAHASH lista[], int localizacao){
    printf("[%d] ", localizacao);
    showList(&lista[localizacao]);
}



void deleteList(TABELAHASH *lista, int valor, int tam){
    no *sec, *del = NULL;
    if (lista->list){
        if (lista->list->chave==valor){
            del= lista->list;
            lista->list = del->proximo;
            lista->height--;
        }
        else{
            sec = lista->list;
            while(sec->proximo && sec->proximo->chave!=valor){
                sec = sec->proximo;
            }
            if (sec->proximo){
                del = sec->proximo;
                sec->proximo = del->proximo;
                lista->height--;
            }
        }
    }
}

void deleteHASH(TABELAHASH lista[], int valor, int num){
    int localizacao = functionHASH(valor, num);
    deleteList(&lista[localizacao], valor, num);
}





int main(){
    int tamanho, search, show, i, cont1=0;
    scanf("%d", &tamanho);
    //criando tabela hash
    TABELAHASH tabela[tamanho];
    //inicializando a tabela
    startHASH(tabela, tamanho);

    
    //lendo os respectivos valores da tabela
    int vetor[max];
    for(i=0; i<max; i++){
        scanf("%d", &vetor[i]);
        if (vetor[i]<0)
            i = max;
        else
            cont1++;
    }

    //lendo o numero a ser pesquisado
    scanf("%d", &search);
    //numero da linha que sera impressa a lista
    scanf("%d", &show);

    //inserindo os valores na tabela
    for(i=0; i<cont1; i++){
        insertionHASH(tabela, vetor[i], tamanho);
    }

    if (searchHASH(tabela, search, tamanho)==0){
        printf("Valor não encontrado");
    }
    else   
        deleteHASH(tabela , search, tamanho);


    printf("\n");
    showHASH(tabela, show);
return 0;
}






