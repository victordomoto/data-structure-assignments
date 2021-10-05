/* Nome: Victor Akio Domoto    */
/* AEDII - UNIFESP             */

#include <stdio.h>
#include <stdlib.h>

int main(){
    //quantNum = tamanho do vetor
    int quantNum, i, cont;
    scanf("%d", &quantNum);
    //sequenciaNum = numeros do vetor (sequencia de entrada)
    int sequenciaNum[quantNum];
    
    for(i=0; i<quantNum; i++){
        scanf("%d", &sequenciaNum[i]);
    }

    //cont = contagem de quantas vezes é efetuada a troca par a par
    cont = ordena(quantNum, sequenciaNum);

    //printando o resultado do vetor ordenado
    for(i=0; i<quantNum; i++){
        printf("%d ", sequenciaNum[i]);
    }
    printf("\n");
    
    
    if ((cont%2)==0){
        printf("Carlos");
    }
    else
        printf("Marcelo");
   
return 0;
}

//função para ordenar o vetor e descobrir a quantidade de trocas realizadas (bubble insertion)
int ordena(int quantNum, int sequenciaNum[quantNum]){
    int i, ult, cont=0; //ult = última constante do vetor. Como ela sempre estará ordenada, não é preciso executar o laço for novamente
    for(ult = quantNum-1; ult>0; ult--){
        for(i=0; i<ult; i++){
            if (sequenciaNum[i] > sequenciaNum[i+1]){   //comparação feita par a par com os números de entrada
                int aux = sequenciaNum[i];              //aux guarda o número caso esteja desordenado
                sequenciaNum[i] = sequenciaNum[i+1];    //invertedo os pares 
                sequenciaNum[i+1] = aux;                //devolvendo o número (na posição i+1)
                cont++;                                 //contagem para saber quantas vezes é exetuada essa troca
            }
        }
    }
return cont; 
}