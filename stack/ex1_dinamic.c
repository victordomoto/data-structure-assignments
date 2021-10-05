/*Nome: Victor Akio Domoto*/
/*AEDI - UNIFESP          */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 52

//calculadora RPN por ponteiro


typedef struct TPilha{
    float v;
    float elemntos [max];
    struct TPilha *prox;
}TPilha;

typedef struct Pilha{
    TPilha *Topo;
}Pilha;

void TpilhaInicia(Pilha *p){
    p->Topo = NULL;
}

void TPilhaInsere (Pilha *p, float dado){
    TPilha *ptr = (TPilha *) malloc (sizeof (TPilha));
    if (ptr == NULL){
    
    }
    else {
        ptr->v = dado;
        ptr->prox = p->Topo;
        p->Topo=ptr;
    }
}
float TPilhaRemove (Pilha *p){
    TPilha * ptr = p->Topo;
    float dado;
    if (ptr == NULL){
        
    }
    else{
        p->Topo = ptr->prox;
        ptr->prox = NULL;
        dado = ptr->v;
        free(ptr);
        return dado;
    }

}
void imprimePilha (Pilha *p){
    TPilha *ptr = p->Topo;
    if (ptr == NULL){
        return;
    }
    else{
        while (ptr!=NULL){
            printf("%f", ptr->v);
            ptr=ptr->prox;

    }
    
    
    }
}


int main(){
    Pilha *p = (Pilha *) malloc (sizeof(Pilha));
    if (p == NULL){
        exit(0);
    }
    else{
        TpilhaInicia(p);
    }

    char s[max];
    float v;
    int tamanho, cont=0, cont2=0, j, i;
    gets(s);

    tamanho=strlen(s);
    for (j=0; j<tamanho; j++){
        if(s[j]=='+' || s[j]=='-' || s[j]=='*' || s[j]=='/'){
        cont++;
        }
    }
    float a=0, b=0, c=0;
    cont2=tamanho-cont;
 
    
    
    for ( j=0; j<tamanho; j++){
        switch (s[j]){
            case '+':
            a= TPilhaRemove(p);
            b=TPilhaRemove(p);
            TPilhaInsere(p, b+a);
            break;
            
            case '-':
                a=TPilhaRemove(p);
                b=TPilhaRemove(p);

                TPilhaInsere(p, b-a);
                break;

            case '*':
                a=TPilhaRemove(p);
                b=TPilhaRemove(p);

                TPilhaInsere(p, b*a);
                break;
            case '/':
                a= TPilhaRemove(p);
                b= TPilhaRemove(p);
                TPilhaInsere(p, b/a);
                break;
            
            default:
                scanf("%f", &v);
                TPilhaInsere(p, v);
        }
    }
    imprimePilha(p);
return 0;
}

