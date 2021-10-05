/* NOME: VICTOR AKIO DOMOTO
Arvore AVL - atividade 9/10 
AEDII - UNIFESP
*/
#include<stdio.h>
#include<stdlib.h>
#define MAXTAMANHO 10000
 
struct NODE{
    int key;
    int height;
    struct NODE *left;
    struct NODE *right;
};

typedef struct NODE* avlTree;

avlTree* createAvlTree(){
    avlTree* root = (avlTree*) malloc(sizeof(avlTree));
    if(root != NULL)
        *root = NULL;
    return root;
}

int heightNode(struct NODE* node){
    if(node == NULL)
        return -1;
    else
    return node->height;
}
struct NODE* searchValue(avlTree *root, int key){
    if(root == NULL){
        return NULL;
    }    else {
            if ((*root)->key== key) 
            return root;
            else{
            if (key < (*root)->key)
                return searchValue(&((*root)->left), key);
                else
                return searchValue(&((*root)->right), key);
            }
    } 
}

int balancing(struct NODE* node){
    return labs(heightNode(node->left) - heightNode(node->right));
}

int bigger(int a, int b){
    if(a > b)
        return a;
    else
        return b;
}


int heightAvlTree(avlTree *root){
    if (root == NULL)
        return 0;
    if (*root == NULL)
        return 0;
    int alt_esq = heightAvlTree(&((*root)->left));
    int alt_dir = heightAvlTree(&((*root)->right));
    if (alt_esq > alt_dir)
        return (alt_esq + 1);
    else
        return(alt_dir + 1);
}

int heightLeftAvlTree(avlTree *root){
    if (root == NULL)
        return 0;
    if (*root == NULL)
        return 0;
    int alt_esq = 1 + heightAvlTree(&((*root)->left));
return alt_esq;

}
int heightRightAvlTree(avlTree *root){
    if (root == NULL)
        return 0;
    if (*root == NULL)
        return 0;
    int alt_dir =1 + heightAvlTree(&((*root)->right));
return alt_dir;
}

int searchAvlTree(avlTree *root, int key){
    if(root == NULL)
        return 0;
    struct NODE* atual = *root;
    while(atual != NULL){
        if(key == atual->key){
            return 1;
        }
        if(key > atual->key)
            atual = atual->right;
        else
            atual = atual->left;
    }
    return 0;
}


void rotationLL(avlTree *nodeA){
    struct NODE *nodeB;
    nodeB = (*nodeA)->left;
    (*nodeA)->left = nodeB->right;
    nodeB->right = *nodeA;
    (*nodeA)->height = bigger(heightNode((*nodeA)->left),heightNode((*nodeA)->right)) + 1;
    nodeB->height = bigger(heightNode(nodeB->left),(*nodeA)->height) + 1;
    *nodeA = nodeB;
}

void rotatioRR(avlTree *nodeA){
    struct NODE *nodeB;
    nodeB = (*nodeA)->right;
    (*nodeA)->right = nodeB->left;
    nodeB->left = (*nodeA);
    (*nodeA)->height = bigger(heightNode((*nodeA)->left),heightNode((*nodeA)->right)) + 1;
    nodeB->height = bigger(heightNode(nodeB->right),(*nodeA)->height) + 1;
    (*nodeA) = nodeB;
}

void rotatioLR(avlTree *nodeA){
    rotatioRR(&(*nodeA)->left);
    rotationLL(nodeA);
}

void rotationRL(avlTree *nodeA){
    rotationLL(&(*nodeA)->right);
    rotatioRR(nodeA);
}

int insertAvlTree(avlTree *root, int number){
    int answer;
    if(*root == NULL){
        struct NODE *new;
        new = (struct NODE*)malloc(sizeof(struct NODE));
        if(new == NULL)
            return 0;

        new->key = number;
        new->height = 0;
        new->left = NULL;
        new->right = NULL;
        *root = new;
        return 1;
    }

    struct NODE *atual = *root;
    if(number < atual->key){
        if((answer = insertAvlTree(&(atual->left), number)) == 1){
            if(balancing(atual) >= 2){
                if(number < (*root)->left->key ){
                    rotationLL(root);
                }else{
                    rotatioLR(root);
                }
            }
        }
    }else{
        if(number > atual->key){
            if((answer = insertAvlTree(&(atual->right), number)) == 1){
                if(balancing(atual) >= 2){
                    if((*root)->right->key < number){
                        rotatioRR(root);
                    }else{
                        rotationRL(root);
                    }
                }
            }
        }else{
            return 0;
        }
    }

    atual->height = bigger(heightNode(atual->left),heightNode(atual->right)) + 1;

    return answer;
}

struct NODE* searchSmaller(struct NODE* atual){
    struct NODE *no1 = atual;
    struct NODE *no2 = atual->left;
    while(no2 != NULL){
        no1 = no2;
        no2 = no2->left;
    }
    return no1;
}

int deleteAvlTree(avlTree *root, int number){
	if(*root == NULL){
	    return 0;
	}

    int res;
	if(number < (*root)->key){
	    if((res = deleteAvlTree(&(*root)->left,number)) == 1){
            if(balancing(*root) >= 2){
                if(heightNode((*root)->right->left) <= heightNode((*root)->right->right))
                    rotatioRR(root);
                else
                    rotationRL(root);
            }
	    }
	}

	if((*root)->key < number){
	    if((res = deleteAvlTree(&(*root)->right, number)) == 1){
            if(balancing(*root) >= 2){
                if(heightNode((*root)->left->right) <= heightNode((*root)->left->left) )
                    rotationLL(root);
                else
                    rotatioLR(root);
            }
	    }
	}

	if((*root)->key == number){
	    if(((*root)->left == NULL || (*root)->right == NULL)){
			struct NO *oldNode = (*root);
			if((*root)->left != NULL)
                *root = (*root)->left;
            else
                *root = (*root)->right;
			free(oldNode);
		}else {
			struct NODE* temp = searchSmaller((*root)->right);
			(*root)->key = temp->key;   
			deleteAvlTree(&(*root)->right, (*root)->key);
            if(balancing(*root) >= 2){
				if(heightNode((*root)->left->right) <= heightNode((*root)->left->left))
					rotationLL(root);
				else
					rotatioLR(root);
			}
		}
		if (*root != NULL)
            (*root)->height = bigger(heightNode((*root)->left),heightNode((*root)->right)) + 1;
		return 1;
	}

	(*root)->height = bigger(heightNode((*root)->left),heightNode((*root)->right)) + 1;

	return res;
}

int heightSubAvlTree(struct NODE *root, int number){
    struct NODE* sub = searchValue(root, number);
    if (sub){
        printf ("%d, %d, %d", heightAvlTree(sub)-1, heightLeftAvlTree(sub)-1, heightRightAvlTree(sub)-1);
    }

}
int main()
{
  avlTree* avl = createAvlTree();

  int i, n, cont1=0, cont2=0;
  int vetor1[MAXTAMANHO], vetor2[MAXTAMANHO];

  //leitura do vetor 1
  for (i=0; i<MAXTAMANHO; i++){
    scanf("%d", &vetor1[i]);
    if (vetor1[i]<0){
        i = MAXTAMANHO;
    }
    else
        cont1++;

  }
  //leitura do vetor 2
  for(i=0; i<MAXTAMANHO; i++){
      scanf("%d", &vetor2[i]);
      if (vetor2[i]<0){
          i = MAXTAMANHO;
      }
      else
        cont2++;
  }
  //leitura do numero a ser pesquisado na arvore
  scanf("%d", &n);
  //inserindo o vetor 1 na arvore
  for(i = 0; i < cont1; i++){
      insertAvlTree(avl, vetor1[i]);
  }
  printf("%d, %d, %d", heightAvlTree(avl)-1, heightLeftAvlTree(avl)-1, heightRightAvlTree(avl)-1);
  printf("\n");

  //inserindo o vetor 2 na arvore, caso satisfaca as condicoes:
  for(i = 0; i<cont2; i++){
      if (searchAvlTree(avl, vetor2[i])==0){
          insertAvlTree(avl, vetor2[i]);
      }
      else
        deleteAvlTree(avl, vetor2[i]);
  }

  //verificando se o valor pesquisado existe
  if (searchAvlTree(avl, n)==0){
      printf("Valor nao encontrado");
  }
  else
    heightSubAvlTree(avl, n);
    
 
  return 0;
}