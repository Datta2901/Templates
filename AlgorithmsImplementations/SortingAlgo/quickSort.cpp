#include <iostream>

using namespace std;
void swap(int* x, int* y){
    int temp = *x;
    *x = *y;
    *y = temp;
}
 
int partitionA(int A[], int low, int high){
    int pivot = A[low];
    int i = low;
    int j = high;
 
    do {
        do {i++;} while (A[i] <= pivot);
 
        do {j--;} while (A[j] > pivot);
 
        if (i < j){
            swap(&A[i], &A[j]);
        }
    } while (i < j);
 
    swap(&A[low], &A[j]);
    return j;
}
 
void QuickSortA(int A[], int low, int high){
    if (low < high){
        int j = partitionA(A, low, high);
        QuickSortA(A, low, j);
        QuickSortA(A, j+1, high);
    }
}
 
int partitionLast(int A[], int low, int high){
    int pivot = A[high];
    int i = low - 1;
    for (int j=low; j<=high-1; j++){
        if (A[j] < pivot){
            i++;
            swap(&A[i], &A[j]);
        }
    }
    swap(&A[i+1], &A[high]);
    return i+1;
}
 
void QuickSortLast(int A[], int low, int high){
    if (low < high){
        int p = partitionLast(A, low, high); 
        QuickSortLast(A, low, p-1); 
        QuickSortLast(A, p+1, high);
    }
}
 
int partition(int A[], int low, int high){
    int pivot = A[low];
    int i = low + 1;
    int j = high;
 
    while (true){
        while (i <= j && A[i] <= pivot){
            i++;
        }
        while (A[j] >= pivot && j >= i){
            j--;
        }
        if (j < i){
            break;
        } else {
            swap(&A[i], &A[j]);
        }
    }
    swap(&A[low], &A[j]);
    return j;
}
 
void QuickSort(int A[], int low, int high){
    if (low < high){
        int p = partition(A, low, high);
        QuickSort(A, low, p-1);
        QuickSort(A, p+1, high);
    }
}
