#include<bits/stdc++.h>
using namespace std;

const int size = 1e6 + 1;
int arr[size];

int seg[4 * size];

void build(int low,int high,int index){
    if(low == high){
        seg[index] = arr[low];
    }else{
        int mid = low + (high - low ) / 2;
        build(low,mid,2 * index + 1);           
        build(mid + 1,high,2 * index + 2); 
        seg[index] = seg[2 * index + 1] + seg[2 * index + 2];
    }
}

int query(int low,int high,int index,int l,int r){
    if( high < l || low > r){
        return 0;
    }
    if(l <= low && r >= high){
        return seg[index];
    }
    int mid = low + (high - low) / 2;
    return query(low,mid,2 * index + 1,l,r) + query(mid + 1,high,2 * index + 2,l,r);
}

void update(int low,int high,int pos,int index,int diff){
    if(pos < low  || pos > high){
        return;
    }
    seg[index] = seg[index] + diff;
    if(low < high){
        int mid = (low + high)/ 2;
        update(low,mid,pos,2 * index + 1,diff);
        update(mid + 1,high,pos,2 * index + 2,diff);
    }
}



void printSeg(int seg[],int size){
    cout << "Segment Tree is : " << " ";
    for(int i = 0; i <= 4 * size; i++){
        cout << seg[i] << " ";
    }
    cout << endl;
}

int main(){
    int s;
    cin >> s;
    for(int i = 0; i < s; i++){
        cin >> arr[i];
    }
    build(0,s - 1,0);
    printSeg(seg,s);
    int q;
    cin >> q;
    while(q--){
        int k;
        cin >> k;
        if(k == 1){
            int l,r;
            cin >> l >> r;
            cout << query(0,s - 1,0,l,r) << endl;
        }else if(k == 2){
            int pos,val;
            cin >> pos >> val;
            int diff = val - arr[pos];
            arr[pos] = val;
            update(0,s - 1,pos,0,diff);
            printSeg(seg,s);
        }
    }
    return 0;
}

