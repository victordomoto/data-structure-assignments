/*Nome: Victor Akio Domoto   */
/*AEDII - UNIFESP            */

#include <stdio.h>
#include <stdlib.h>

typedef int TipoPeso;
typedef int TipoVertice;
    struct grafo {
    int NumVertices;
    int NumArestas;
TipoPeso **Mat;
 };

typedef struct grafo TipoGrafo;

TipoGrafo* Cria_grafo(int NVertices){
    int i, k;
    TipoGrafo *Grafo ;
    if (NVertices <= 0) return NULL;
    Grafo = (TipoGrafo*) malloc(sizeof(TipoGrafo));
    if (Grafo == NULL) return NULL;
    Grafo->Mat = (TipoPeso **) malloc(NVertices*sizeof(TipoPeso*));
    if (Grafo->Mat == NULL){
         free(Grafo);
        return NULL;
  }
    for(i=0; i<NVertices; i++){
        Grafo->Mat[i] = (TipoPeso*) calloc(NVertices,sizeof(TipoPeso));
    //aloca e preenche com zeros
    if (Grafo->Mat[i] == NULL) { // não conseguiu alocar a linha i da matriz
    for (k=0; k<i; k++);
    return NULL;
    }
}
    Grafo->NumVertices = NVertices;
    Grafo->NumArestas = 0;
    return Grafo;
}

int Insere_Aresta(TipoGrafo *Grafo, TipoVertice v1,
    TipoVertice v2, TipoPeso peso){
    if (Grafo == NULL)
        return -1; // o grafo não existe
    if (v1<0 || v1>= Grafo->NumVertices || v2 < 0 ||
    v2 >= Grafo->NumVertices)
    return -1; // não eh possivel criar aresta
    if (Grafo->Mat[v1][v2] != 0 || peso <= 0)
    return 0; // já existe aresta entre v1 e v2
    // ou peso invalido

    Grafo->Mat[v1][v2] = peso;
    Grafo->NumArestas ++;
    return 1;
}

int Existe_Aresta(TipoGrafo *Grafo, TipoVertice v1,TipoVertice v2){
if (Grafo == NULL)
    return -1;
if (v1<0 || v1>= Grafo-> NumVertices || v2 < 0 ||
    v2 >= Grafo->NumVertices)
return -1; // nao eh possivel criar aresta
if( Grafo->Mat[v1][v2] == 0)
    return 0; //aresta nao existe ligando v1 e v2
else return 1; //existe aresta ligando v1 e v2
}

int Retira_Aresta(TipoGrafo *Grafo, TipoVertice v1, TipoVertice v2){
 if (Grafo == NULL)
    return -1; // grafo nao existe
 if (v1<0 || v1>=Grafo-> NumVertices ||v2<0 || v2>=Grafo-> NumVertices)
    return -1; // nao eh possivel criar aresta
 if( Grafo->Mat[v1][v2] == 0)
    return 0; // aresta nao existe

Grafo->Mat[v1][v2] = 0; //remove aresta
Grafo->NumArestas--;
return 1;
}

int Consulta_Aresta(TipoGrafo *Grafo, TipoVertice v1,TipoVertice v2, TipoPeso* peso){
if (Grafo == NULL)
    return -1;
if (v1<0 || v1>= Grafo-> NumVertices ||v2<0 || v2>= Grafo-> NumVertices)
    return -1; // vertices invalidos
if (Grafo->Mat[v1][v2] == 0)
    return 0;
*peso = Grafo->Mat[v1][v2];
return 1;
}
void Mostra_Lista_Adjacentes(TipoGrafo *Grafo,TipoVertice v){
int i, cont =0 ;
if (Grafo == NULL || v<0 || v >= Grafo->NumVertices)
    return 0;
else {
for (i=0; i<Grafo->NumVertices; i++)
    if (Grafo->Mat[v][i] != 0){
        printf("%d -%d", i, Grafo->Mat[v][i]);
        cont = 1;
 }
if (cont == 0)
   return 0;
}
}
void Mostra_Grafo(TipoGrafo *Grafo){
int i, j, k=0;
int depende[100];
int dependencia[100];
if (Grafo == NULL || Grafo->NumArestas == 0)
    return 0;
else
for(i=0; i<100;i++){
    depende[i]=0;
    dependencia[i]=0;
}
for (i=0; i<Grafo->NumVertices; i++){
    for (j=0; j<Grafo->NumVertices; j++){
         dependencia[i]++;
        if (Grafo->Mat==Grafo->Mat){
            k=Grafo->Mat[i][j];
            depende[k]++;
        } 
    }
 }

for (i=1; i<=Grafo->NumVertices; i++){
    printf("%d %d %d ", i, depende[i], dependencia[i]);
    for (j=0; j<Grafo->NumVertices; j++){
        printf("%d ", Grafo->Mat[i][j]);
    }
    printf("\n");
 }
 

}

int main(){
    int n=0, d=0;
    scanf("%d %d", &n, &d);
    if (n<=100 && d<=10000){
    TipoGrafo* gr = Cria_grafo(n);  
    int i, vertice, aresta, j;
    for(i=0; i<d; i++){
        scanf("%d %d", &vertice, &aresta);
        Insere_Aresta(gr, vertice, aresta,1);   
    }

    Mostra_Grafo(gr);
return 0;
    }
return 0;
    
    
}
