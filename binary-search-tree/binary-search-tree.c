/*Exercicio 8 JUDGE
Nome: Victor Akio Domoto
RA: 150546
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 10000

//Arvore Binaria de Busca

struct NO{
    int key;
    struct NO *left;
    struct NO *right;
};
typedef struct NO *binTree;

//(1)Inicializacao da arvore 
binTree* start_binTree(){
    binTree* raiz = (binTree*) malloc(sizeof(binTree));
    if(raiz != NULL)
        *raiz = NULL;
    return raiz;
}

//(3)Insere um valor na arvore 
int addBinTree(binTree* raiz, int valor){
    if(raiz == NULL)
        return 0;
    struct NO* novo;
    novo = (struct NO*) malloc(sizeof(struct NO));
    if(novo == NULL)
        return 0;
    novo->key = valor;
    novo->right = NULL;
    novo->left = NULL;

    if(*raiz == NULL)
        *raiz = novo;
    else{
        struct NO* atual = *raiz;
        struct NO* ant = NULL;
        while(atual != NULL){
            ant = atual;
            if(valor == atual->key){
                free(novo);
                //printf("%d ", valor);
                return 0;//elemento já existe
            }

            if(valor > atual->key){
                atual = atual->right;
                
            }
            else{
                atual = atual->left;
                
            }
                
        }
        if(valor > ant->key)
            ant->right = novo;
        else
            ant->left = novo;
    }
    return 1;
}

struct NO* DeleteNo(struct NO* atual) {
    struct NO *no1, *no2;
    if(atual->left == NULL){
        no2 = atual->right;
        free(atual);
        return no2;
    }
    no1 = atual;
    no2 = atual->left;
    while(no2->right != NULL){
        no1 = no2;
        no2 = no2->right;
    }
    // no2 é o nó anterior a r na ordem e-r-d
    // no1 é o pai de no2
    if(no1 != atual){
        no1->right = no2->left;
        no2->left = atual->left;
    }
    no2->right = atual->right;
    free(atual);
    return no2;
}

//(4)Remocao de um valor da arvore.
int deleteBinTree(binTree *raiz, int valor){
    if(raiz == NULL)
        return 0;
    struct NO* ant = NULL;
    struct NO* atual = *raiz;
    while(atual != NULL){
        if(valor == atual->key){
            if(atual == *raiz)
                *raiz = DeleteNo(atual);
            else{
                if(ant->right == atual)
                    ant->right = DeleteNo(atual);
                else
                    ant->left = DeleteNo(atual);
            }
            return 1;
        }
        ant = atual;
        if(valor > atual->key)
            atual = atual->right;
        else
            atual = atual->left;
    }
    return 0;
}



int heightBinTree(binTree *raiz){
    if (raiz == NULL || *raiz == NULL || (&((*raiz)->left))== NULL && (&((*raiz)->right)) == NULL)
        return 0;
    else{
        int alt_esq = 1 + heightBinTree(&((*raiz)->left));
        int alt_dir = 1 + heightBinTree(&((*raiz)->right));
        if (alt_esq > alt_dir){
         return (alt_esq);
    }   
    else
        return(alt_dir);
    }
}
struct NO* searchValue(binTree *raiz, int valor){
    if(raiz == NULL){
        return NULL;
    }    else {
            if ((*raiz)->key== valor) 
            return raiz;
            else{
            if (valor < (*raiz)->key)
                return searchValue(&((*raiz)->left), valor);
                else
                return searchValue(&((*raiz)->right), valor);
            }
    } 
}


//(2)Pesquisa de algum valor na arvore. Caso ele exista, retornara 1, caso contrario 0
int searchBinTree(binTree *raiz, int valor){
    if(raiz == NULL)
        return 0;
    struct NO* atual = *raiz;
    while(atual != NULL){
        if(valor == atual->key){
            return 1;
        }
        if(valor > atual->key)
            atual = atual->right;
        else
            atual = atual->left;
    }
    return 0;
}

int heightLeft(binTree *raiz){
    if (raiz == NULL)
        return 0;
    if (*raiz == NULL)
        return 0;
    int alt_esq = 1 + heightBinTree(&((*raiz)->left));
return alt_esq;
}

int heightRight(binTree *raiz){
    if (raiz == NULL)
        return 0;
    if (*raiz == NULL)
        return 0;
    int alt_dir = 1 + heightBinTree(&((*raiz)->right));
return alt_dir;
}


int heightSubTree(struct NO *raiz, int valor){
    struct NO* sub = searchValue(raiz, valor);
    if (sub){
        printf ("%d, %d, %d", heightBinTree(sub)-1, heightLeft(sub)-1, heightRight(sub)-1);
        //imprimeEsquerda(sub);
        //printf("\n");
        //emOrdem_ArvBin(sub);
    }

}

void emOrdem_ArvBin(binTree *raiz){
    if(raiz == NULL)
        return;
    if(*raiz != NULL){
        emOrdem_ArvBin(&((*raiz)->left));
        printf("%d ",(*raiz)->key);
        emOrdem_ArvBin(&((*raiz)->right));
    }
}
void imprimeEsquerda(binTree *raiz){
    if(raiz == NULL)
        return;
    if(*raiz != NULL){
        imprimeEsquerda(&((*raiz)->left));
        printf("\nESQUERDA: %d ",(*raiz)->key);
    }
}


int main(){
    //struct NO * raiz
    binTree* raiz = start_binTree();
    int i, n, cont1=0, cont2=0;
    int vetor1[max], vetor2[max];
    //n eh o numero q sera pesquisado

    //lendo vetor1
    for(i=0; i<max; i++){
        scanf("%d", &vetor1[i]);
        if (vetor1[i]<0){
            i = max;
        }
        else{
            cont1++;
        }
        }
        
    //lendo vetor 2
        for(i=0; i<max; i++){
        scanf("%d", &vetor2[i]);
        if (vetor2[i]<0){
            i = max;
        }
        else{
            cont2++;
        }
        }
        
    //n eh o numero a ser pesquisado
    scanf("%d", &n); 
    for(i=0; i< cont1; i++){
        addBinTree(raiz, vetor1[i]);
    }
    printf ("%d, %d, %d", heightBinTree(raiz)-1, heightLeft(raiz)-1, heightRight(raiz)-1);
    
    for(i=0; i < cont2; i++){
        if (searchBinTree(raiz, vetor2[i])==0){
            addBinTree(raiz, vetor2[i]);
        }
        else
            deleteBinTree(raiz, vetor2[i]);
    }

    printf("\n");
    if (searchBinTree(raiz, n)==0){
        printf("Valor nao encontrado");
    }
    else
        heightSubTree(raiz,n);

return 0;
}

