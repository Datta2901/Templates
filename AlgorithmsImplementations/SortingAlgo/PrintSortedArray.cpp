#include <iostream>
using namespace std;
 
template <class T>
void Print(T& vec, int n, string s){
    cout << s << ": [" << "";
    for (int i=0; i<n; i++){
        cout << vec[i] << "";
        if (i < n-1){
            cout << ", " << "";
        }
    }
    cout << "]" << endl;
}
 