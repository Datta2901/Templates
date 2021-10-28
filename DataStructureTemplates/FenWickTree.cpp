#include<bits/stdc++.h>
using namespace std;

struct Fenwick{
    int size;
    vector<int>arr,Fen;
    Fenwick(vector<int>nums){
        arr = nums;
        size = nums.size();
        Fen.resize(size + 1);
        fill(Fen.begin(),Fen.end(),0);
    }
    int getSum(int i){
        i = i + 1; 
        int sum = 0;
        while(i > 0){
            sum = sum + Fen[i];
            i =  i - (i & (-i));    
        }
        return sum;
    }

    void Update(int i,int diff){
        arr[i] += diff;
        i = i + 1;
        while(i <= size){
            Fen[i] += diff;
            i = i + (i & -i);
        }
    }

    int getRange(int left,int right){
        return getSum(right) - getSum(left - 1);
    }

     void _printFen(){
        for(int i = 1; i < Fen.size(); i++){
            cout << Fen[i] << ' ';
        }
    }

};

int main(){
    int size;
    cin >> size;
    vector<int>arr;
    for(int i = 0; i < size; i++){
        int a;
        cin >> a;
        arr.push_back(a);
    }
    Fenwick ft(arr);

    for(int i = 0; i < size; i++){
        ft.Update(i,arr[i]);
    }   

    int q;
    cin >> q;
    while(q--){
        int type;
        cin >> type;
        if(type == 1){
            int l,r;
            cin >> l >> r;
            cout << ft.getRange(l,r) << endl;
        }else if(type == 2){
            int pos,val;
            cin >> pos >> val;
            int diff = val - arr[pos];
            ft.Update(pos,diff);
        }else{
            ft._printFen();
        }
    }

    return 0;
}