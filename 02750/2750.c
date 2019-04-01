#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void insertionSort(int A[], const int n){

    for(int i=1; i<n; i++){

        int key = i;

        for(int j=i-1; j>=0; j--){
            if(A[j] > A[key]){
                swap(&A[key], &A[j]);
                key = j;
            }
        }
    }
    return;
}
int main(){
    int n = 0;
    scanf("%d", &n);

    int *A = (int*)calloc(n, sizeof(int));

    for(int i=0; i<n; i++){
        scanf("%d", &A[i]);
    }

    insertionSort(A, n);

    for(int i=0; i<n; i++){
        printf("%d\n", A[i]);
    }
    free(A);

    return 0;
}

