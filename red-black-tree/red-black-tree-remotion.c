/* Nome: Victor Akio Domoto                  */
/* Atividade 12 - REMOÇÃO ÁRVORE RUBRO NEGRA */
/* AEDII - UNIFESP                           */

#include<stdio.h>
#include<stdlib.h>
#define max 100000
#include <math.h>

enum Color {RED, BLACK};
typedef enum Color ColorType; 


struct Node {
    int chave;
    ColorType color;
    struct Node* parent;
    struct Node *left, *right;
};

struct Node *root, *nodonull;


//Criando Arvore
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

//rotaciona arvore pra esquerda
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

//rotaciona arvore pra direita
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
        if (p->parent == p->parent->parent->left) {  
            tio = p->parent->parent->right;
            if (tio->color == RED) {           
                p->parent->color = BLACK;        
                tio->color = BLACK;
                p->parent->parent->color = RED;
                p = p->parent->parent;
            }
            else {                       
                if (p == p->parent->right){        
                    p = p->parent;              
                    r = treeRotateLeft(r, p);
                }else {
                p->parent->color = BLACK;       
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

/* PARTE DE REMOCAO- ARVORE RUBRO NEGRA */
struct Node* next(struct Node* p) {
    struct Node* aux;
    if (p->right == nodonull)
        return nodonull;
    aux = p->right;
    while (aux->left != nodonull){
        aux = aux->left;
    }
    return aux;
}
void deleteFixUp (struct Node* t, struct Node* x) {
struct Node* w;
while( x != t && x->color == BLACK ){
		if( x == x->parent->left ){
			w = x->parent->right;
			if( w->color == RED ){
				w->color = BLACK; 
				x->parent->color = RED ; 
				treeRotateLeft(t, x->parent); 
				w = x->parent->right;

			}
			if( w->left->color == BLACK  && w->right->color == BLACK ){
				w->color = RED; 
				x = x->parent;
			}
			else{
				
				if( w->right->color == BLACK ){
					w->left->color = BLACK; 
					w->color = RED;	
					treeRotateRight(t, w);
					w = x->parent->right;
				}
				w->color = x->parent->color;
				x->parent->color = BLACK;
				w->right->color = BLACK;
				treeRotateLeft(t, x->parent);
				x = t;
			}
		}	
		else{
			w = x->parent->left;
			if( w->color == RED ){
				w->color = BLACK; 
				x->parent->color = RED ; 
				treeRotateRight(t, x->parent); 
				w = x->parent->left;
			}
			if( w->left->color == BLACK  && w->right->color == BLACK ){
				w->color = RED; 
				x = x->parent;
			}
			else{
				if( w->left->color == BLACK ){
					w->right->color = BLACK;
					w->color = RED;	
					treeRotateLeft(t,w);
					w = x->parent->left;
				}
				w->color = x->parent->color;
				x->parent->color = BLACK;
				w->left->color = BLACK;
				treeRotateRight(t, x->parent);
				x = t;
			}
		}
	}	
	x->color = BLACK; 

}
void deleteTree (struct Node* r, struct Node* nodok) { 
    struct Node * delNode, *filho;
    if (nodok == nodonull)
        return;
    if (nodok->left == nodonull || nodok->right == nodonull)
    /* se nodok tem 0 ou 1 filho, remove nodok */
        delNode = nodok;                               
    else                          
        delNode = next (nodok);  
    if (delNode->left != nodonull)
        filho = delNode->left;
    else
        filho = delNode->right;
    filho->parent = delNode->parent;
    if (delNode->parent == nodonull)
        r = filho;
    else if (delNode == delNode->parent->left)
        delNode->parent->left = filho;
    else
        delNode->parent->right = filho;
    if (nodok != delNode) 
        nodok->chave = delNode->chave;


    if (delNode->color == BLACK){
        deleteFixUp (r, filho);
    }
  
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
        else{
            heightSubTree(root, vetor2[i]);
            struct Node* aux = nodeSearch(root, vetor2[i]);
                if (aux)
                    deleteTree(root, aux);
        } 
    }
    //showInOrdem(root);

    if (treeSearch(root, n)==0){
        printf("Valor nao encontrado");
    }
    else{
        struct Node *aux = nodeSearch(root, n);
        h = (height(aux)-1)/2;
        if (aux->color==RED)
            printf("%d", h+1);
        else
            printf("%d", h); 
    } 

return 0;
}