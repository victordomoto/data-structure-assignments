/* Nome: Victor Akio Domoto                  */
/* Atividade 12 - JUDGE - ARVORE RUBRO NEGRA */

#include<stdio.h>
#include<stdlib.h>
#define max 10000
#include <math.h>

enum Color {RED, BLACK};
typedef enum Color ColorType; 
//typedef struct Node *Pointer;

struct Node {
    int chave;
    ColorType color;
    struct Node* parent;
    struct Node *left, *right;
};



struct Node *root, *nodonull;


/*criando No*/
struct Node* createTreee ( int num, struct Node *left, struct Node *right, struct Node *parent ) {
    struct Node *p;
    p = (struct Node*) malloc (sizeof (struct Node));
    p->chave = num;
    p->left = left;
    p->right = right;
    p->parent = parent;
	return p;
}
//Iniciando arvore rubro-negra
void startTree (){
    nodonull = createTreee (0, NULL, NULL, NULL);
    nodonull->color = BLACK;
    root = nodonull;
}


/* Rotaciona para esquerda*/
struct Node *treeRotateLeft (struct Node *r, struct Node *p) {
    struct Node *y = p->right;
    p->right = y->left;
    if (y->left != nodonull)
        y->left->parent = p;
    y->parent = p->parent;
    if (p->parent == nodonull)
        r = y;
    else if (p == p->parent->left)
        p->parent->left = y;
    else
        p->parent->right = y;
    y->left = p;
    p->parent = y;
    return r;
}


/*Rotaciona para a direita */
struct Node* treeRotateRight (struct Node *r, struct Node *p) {
    struct Node* y = p->left;
    p->left = y->right;
    if (y->right != nodonull)
        y->right->parent = p;
    y->parent = p->parent;
    if (p->parent == nodonull)
        r = y;
    else if (p == p->parent->left)
        p->parent->left = y;
    else
        p->parent->right = y;
    y->right = p;
    p->parent = y;
    return r;
}

/* Reajusta as cores dos nos depois de uma insercao*/
struct Node *insertFixUp (struct Node *r, struct Node *p ){
    struct Node *tio;
    while (p->parent->color == RED ) {
        if (p->parent == p->parent->parent->left) {  /* Inserindo na sub arvore a esquerda */
            tio = p->parent->parent->right;
            if (tio->color == RED) {           
                p->parent->color = BLACK;        /* Primeiro caso */
                tio->color = BLACK;
                p->parent->parent->color = RED;
                p = p->parent->parent;
            }
            else {                       
                if (p == p->parent->right){        /* Desbalanceamento na subarvore direita do filho a esquerda */
                    p = p->parent;               /* Segundo caso*/ 
                    r = treeRotateLeft(r, p);
                }else {
                p->parent->color = BLACK;        /*Terceiro caso*/
                p->parent->parent->color = RED;
                r = treeRotateRight(r, p->parent->parent ); }
            }
        }
        else{  
            tio = p->parent->parent->left;
            if (tio->color == RED) {           
                p->parent->color = BLACK;        
                tio->color = BLACK;
                p->parent->parent->color = RED;
                p = p->parent->parent;
            }
            else {                       
                if (p == p->parent->left){        
                    p = p->parent;               
                    r = treeRotateRight(r, p);
                }else {
                p->parent->color = BLACK;       
                p->parent->parent->color = RED;
                r = treeRotateLeft(r, p->parent->parent);}
            }
        } 
    }
    r->color = BLACK;
    return r;
}


/*Inserindo um elemento na arvore rubro-negra*/ 
struct Node *insertTree (struct Node *p, int num) {
    struct Node *novo = createTreee (num, nodonull, nodonull, nodonull);
    struct Node* x = p;
    struct Node *parentx = nodonull;
    //Em busca do pai do novo NO
    while (x != nodonull){ 
        parentx = x;
        if (num < x->chave)
            x = x->left;
        else
            x = x->right;
    }
    novo->parent = parentx;
    if (parentx == nodonull)
        p = novo;
    else if (num < parentx->chave)
        parentx->left = novo;
    else 
        parentx->right = novo;
    novo->color = RED;
    p =  insertFixUp (p, novo);
    return p;
}



//Calcula altura da arvore rubro-negra a partir da raiz passada como parametro
int height (struct Node *root){
    if (root == NULL)
        return 0;
 
    int left = height (root->left);
    int right =  height(root->right);
    if (left > right)
        return left+1;
    else
        return right+1;
    
}

//Porcura NO na arvore
struct Node *nodeSearch(struct Node *root, int num){
    if (root==NULL){
        return NULL;
    } else {
        if (root->chave == num)
            return root;
            else{
                if (num < root->chave)
                    return nodeSearch(root->left, num);
                else
                    return nodeSearch(root->right, num);
            }
    }
}
//imprime as alturas da subarvore 
void heightSubTree (struct Node *root, int num){
    struct Node *aux = nodeSearch(root, num);
    if (aux){
        printf("%d, %d, %d", height(aux)-2, height(aux->left)-1, height(aux->right)-1);
        printf("\n");
    }
}



//Busca um elemento na arvore. Caso encontre, retorna 1. Senao, 0
int treeSearch (struct Node *p, int num) {
    if (p == nodonull)
        return 0;
    if (p->chave == num)        
        return 1;
    else if (num < p->chave)
        return treeSearch (p->left, num);
    else
        return treeSearch (p->right, num);
}


//funcao principal
int main(){
    startTree();
    int i,cont1=0, cont2=0, n=0, h=0;
    int vetor1[max], vetor2[max];
    //lendo vetor1
    for(i = 0; i <max; i++){
        scanf("%d", &vetor1[i]);
        if (vetor1[i] < 0)
            i = max;
        else
            cont1++;
    }
    //lendo vetor 2:
    for(i = 0; i <max; i++){
        scanf("%d", &vetor2[i]);
        if (vetor2[i] < 0)
            i = max;
        else
            cont2++;
    }
    //lendo o valor a ser pesquisado para calcular a altura negra
    scanf("%d", &n);
    //inserindo vetor1
    for(i = 0; i < cont1; i++){
        root = insertTree(root, vetor1[i]);
    }

    printf("%d, %d, %d", height(root)-2, height(root->left)-1, height(root->right)-1);
    printf("\n");
    for(i= 0; i < cont2; i++){
        if (treeSearch(root, vetor2[i])==0){
            root = insertTree(root, vetor2[i]);
        }
        else
            heightSubTree(root, vetor2[i]);
    }
   
    //showInOrdem(root);
    
    if (treeSearch(root, n)==0){
        printf("Valor nao encontrado");
    }
    else{
        
        struct Node *sub = nodeSearch(root, n);
        h = (height(sub)-2)/2;
        if (sub->color==BLACK)
            printf("%d", h+1);
        else
            return printf("%d", h); 
    } 

return 0;
}