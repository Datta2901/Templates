#include <iostream>

using namespace std;
 
void swap(int* x, int* y){
    int temp = *x;
    *x = *y;
    *y = temp;
}
 
void SelectionSort(int A[], int n){
    for (int i=0; i<n-1; i++){
        int j;
        int k;
        for (j=k=i; j<n; j++){
            if (A[j] < A[k]){
                k = j;
            }
        }
        swap(&A[i], &A[k]);
    }
}
