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
 
class Node{
public:
    int value;
    Node* next;
};
 
void Insert(Node** ptrBins, int idx){
    Node* temp = new Node;
    temp->value = idx;
    temp->next = NULL;
 
    if (ptrBins[idx] == NULL){ 
        ptrBins[idx] = temp;
    } else {
        Node* p = ptrBins[idx];
        while (p->next != NULL){
            p = p->next;
        }
        p->next = temp;
    }
}
 
int Delete(Node** ptrBins, int idx){
    Node* p = ptrBins[idx];  
    ptrBins[idx] = ptrBins[idx]->next;
    int x = p->value;
    delete p;
    return x;
}
 
void BinSort(int A[], int n){
    int max = Max(A, n);
    Node** bins = new Node* [max + 1];
    for (int i=0; i<max+1; i++){
        bins[i] = NULL;
    }
    for (int i=0; i<n; i++){
        Insert(bins, A[i]);
    }
    int i = 0;
    int j = 0;
    while (i < max+1){
        while (bins[i] != NULL){
            A[j++] = Delete(bins, i);
        }
        i++;
    }
    delete [] bins;
}
 