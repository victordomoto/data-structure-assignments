/*Nome: Victor Akio Domoto      */
/*AEDII - UNIFESP               */

#include <stdio.h>
#include <stdlib.h>

int main(){
    int N, i, k, x;

    scanf("%d", &N);
    scanf("%d", &k);

    int v[N];
    for(i=0; i<N; i++){
        scanf("%d", &v[i]);
    }

    x = mergeSort(v, 0, N-1, k);

    for(i=0; i<N; i++){
        printf("%d ", v[i]);
    }
    printf("\n%d", x);
}


int merge(int vet[], int esq, int meio, int dir, int var)
{
    int cont=0;
    int i, j, k;
    int n1 = meio - esq + 1;
    int n2 = dir - meio;
    int L[n1], R[n2];
 
    
    for (i = 0; i < n1; i++)
        L[i] = vet[esq + i];
    for (j = 0; j < n2; j++)
        R[j] = vet[meio + 1 + j];
 
    /* Merge the temp arrays back into arr[l..r]*/
    i = j = 0; // Initial index of first subarray
    k = esq; // Initial index of merged subarray
    while (i < n1 && j < n2) {
        if (L[i] > R[j]*var) {
            vet[k] = L[i];
            cont++;
            i++;
        }
        else {
            vet[k] = R[j];
            j++;
        }
        k++;
    }
 
    /* Copy the remaining elements of L[], if there
    are any */
    while (i < n1) {
        vet[k] = L[i];
        i++;
        k++;
    }
 
    /* Copy the remaining elements of R[], if there
    are any */
    while (j < n2) {
        vet[k] = R[j];
        j++;
        k++;
    }
return cont;
}
 

int mergeSort(int vet[], int esq, int dir, int k)
{
    if (esq < dir) {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = esq + (dir - esq) / 2;
 
        // Sort first and second halves
        mergeSort(vet, esq, m, k);
        mergeSort(vet, m + 1, dir, k);
 
        merge(vet, esq, m, dir, k);
    }
}
 
