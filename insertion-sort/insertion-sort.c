/*Nome: Victor Akio Domoto  */
/* AEDII - UNIFESP          */

#include <stdio.h>
#include <stdlib.h>

int main(){
    int tam=0, i, tamanhoFixo=0;
    
    scanf("%d", &tam);
    int vetor[tam];

    for(i=0; i<tam; i++){
        scanf("%d", &vetor[i]);
    }

    tamanhoFixo = tam+1;                //tamanho do vetor que sera comparado com n-1
    sort(vetor,tam, tamanhoFixo);     //execucao da funcao para ordenar vetor 

    for(i=0; i<tam; i++){
        printf("%d ", vetor[i]);        //printando vetor ordenado 
       
    }
return 0;
}

//  funcao insertion sort recursiva, para ordenar a entrada de dados (vetor);
void sort(int vetor[], int tam, int tamanhoFixo){
   int i=0, cont=0, ult=0, pos;
    
   if (tam<=1){
        return;
   }
   else{
    cont = tamanhoFixo-tam;   //nivel de recursao
    sort(vetor, tam-1, tamanhoFixo);

    ult = vetor[tam-1];
    i = tam-2; 
    pos = binSearch(ult, tam-1, vetor);
    
    while (i>=0 && vetor[i]>ult){
        vetor[i+1] = vetor[i];
        i--; 
    }
    vetor[pos] = ult;
    printf ("%d %d %d\n", cont, ult, pos);
   }  
return;
}

//funcao de busca binaria para encontrar a localizacao do elemento no vetor
int binSearch (int ult, int tam, int vetor[]) { 
   int esq = 0, dir = tam; 
   while (esq < dir) {  
      int meio = (esq + dir)/2;
      if (vetor[meio] < ult){
          esq = meio+1;
      } 
      else 
        dir = meio; 
   }
   return dir;        //retorna a localizacao
}

