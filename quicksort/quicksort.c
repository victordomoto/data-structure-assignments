/*Nome: Victor Akio Domoto  */
/*AEDII - UNIFESP           */
#include <stdio.h>
#include <stdlib.h>


//funcao q ira separar o array
int divisao(int vetor[],int esquerda, int direita, int constante){
    int posicao = vetor[direita], posicaoLocal = esquerda, i=0;
    int E = esquerda;
    int D = direita;
    for (i = E; i <= D; i++) {
        //usando variavel aux1 para trocar os valores do vetor
        if (vetor[i] < posicao) {
                int aux1 = vetor[i];
                vetor[i] = vetor[posicaoLocal];
                vetor[posicaoLocal] = aux1;
                posicaoLocal++;
            }
        }
 
        //trocando os pivos
        int aux1 = vetor[direita];
        vetor[direita] = vetor[posicaoLocal];
        vetor[posicaoLocal] = aux1;
 
    return posicaoLocal;
}

//ordena ate a posicao do vetor[k]
int quickSort(int vetor[],int esquerda, int direita, int constante){
    int posicao, quickDir, quickEsq;
    int E = esquerda;
    int D = direita;

    posicao = divisao(vetor,E,D, constante);

    if ((constante < posicao) && (constante!=posicao)){
            quickDir = quickSort(vetor, E, posicao-1, constante);
    }
    else 
    if (constante != posicao)
        quickEsq = quickSort(vetor, posicao+1, D, constante);
        
}
int showVetor(int vetor[], int num){
    int i;
    for(i=0; i<num; i++){
        printf("%d ", vetor[i]);
    }
}



int main(){
    int constante, num, i;
    scanf("%d", &constante);
    scanf("%d", &num);
    int vetor[num];

    for(i=0;i <num; i++){
        scanf("%d", &vetor[i]);
    }

    quickSort(vetor,0,num-1, constante-1);



    printf("%do menor elemento eh o %d\n", constante, vetor[constante-1]);

    //funcao q imprime o vetor
    showVetor(vetor, num);
return 0;
}