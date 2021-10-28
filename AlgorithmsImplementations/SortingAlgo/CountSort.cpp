#include <iostream>

using namespace std;
 
int Max(int A[], int n){
    int max = -32768;
    for (int i=0; i<n; i++){
        if (A[i] > max){
            max = A[i];
        }
    }
    return max;
}
 
void CountSort(int A[], int n){
    int max = Max(A, n);
    int* count = new int [max + 1];
    for (int i=0; i<max+1; i++){
        count[i] = 0;
    }
    for (int i=0; i<n; i++){
        count[A[i]]++;
    }
    int i = 0;
    int j = 0;
    while (j < max+1){
        if (count[j] > 0){
            A[i++] = j;
            count[j]--;
        } else {
            j++;
        }
    }
    delete [] count;
}
