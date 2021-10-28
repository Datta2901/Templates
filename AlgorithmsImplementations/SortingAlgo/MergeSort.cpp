#include <iostream>

using namespace std;
 
void Merge(int x[], int y[], int z[], int m, int n){
    int i = 0;
    int j = 0;
    int k = 0;
    while (i < m && j < n){
        if (x[i] < y[j]){
            z[k++] = x[i++];
        } else {
            z[k++] = y[j++];
        }
    }
    while (i < m){
        z[k++] = x[i++];
    }
    while (j < n){
        z[k++] = x[j++];
    }
}
 
void MergeSingle(int A[], int low, int mid, int high){
    int i = low;
    int j = mid+1;
    int k = low;
    int B[high+1];
    while (i <= mid && j <= high){
        if (A[i] < A[j]){
            B[k++] = A[i++];
        } else {
            B[k++] = A[j++];
        }
    }
    while (i <= mid){
        B[k++] = A[i++];
    }
    while (j <= high){
        B[k++] = A[j++];
    }
    for (int i=low; i<=high; i++){
        A[i] = B[i];
    }
}
