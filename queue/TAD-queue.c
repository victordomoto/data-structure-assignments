/*Nome: Victor Akio Domoto    */
/*AED1 - UNIFESP              */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define max 65536

typedef struct TFila{
    int dados[max];
    int indice [max];
    int posicao[max];
    int k;
    int fim;

}TFila;


void inicializaFila(TFila *f){
    int i;

    for(i=0; i<max; i++){
        f->dados[i]=0;
    }

    f->fim = 0;
}

void enfileira (int forcai, TFila *f, int posicao){
    if(f->fim == max){
        return;
    }
    else{
        f->dados[f->fim]= forcai;
        f->posicao[f->fim]=posicao;
        f->fim++;
        
       // printf("%d\n", f->posicao[f->fim]);
    }
    //tentando achar posicao

    
    
}

int desenfileira (TFila *f){
    int forcai, i;
    if (f->fim ==0){
        return;
    }
    else{
        forcai = f->dados[0];
     
        for(i=0; i<f->fim; i++){
            f->dados[i]=f->dados[i+1];
           

        }
    f->fim--;
    return forcai;
    }
}

int desempilhaIndice(TFila *f){
    int posicao, i;
    if (f->fim ==0){
        return;
    }
    else{
        posicao = f->indice[0];
        for(i=0; i<f->fim; i++){
            f->indice[i]=f->indice[i+1];
        }
        f->fim--;
    return posicao;
    printf("%d\n", posicao);
    }

}
