#include<bits/stdc++.h>
using namespace std;


class heap{
private:
    vector<int>nums;
    int size;
public:
    heap(vector<int>nu){
        nums = nu;
        size = nu.size();
    }

    void build(){
        make_heap(nums.begin(),nums.end());
    }

    void push(int a){
        nums.push_back(a);
        push_heap(nums.begin(),nums.end());
    }

    void pop(){
        pop_heap(nums.begin(),nums.end());
        nums.pop_back();
    }

    // After using sorting  method 
    // it is no longer heap

    void sort(){
        sort_heap(nums.begin(),nums.end());
    }

    void print(){
        for(auto it : nums){
            cout << it << " ";
        }
        cout << endl;
    }
};




int main(){
    int size;
    cin >> size;
    vector<int>nums;
    for(int i = 0; i < size; i++){
        int a;
        cin >> a;
        nums.push_back(a);
    }
    heap obj(nums);
    obj.build();
    cout << "after building .. ";
    obj.print();
    obj.push(10);
    cout << "after pushing ..";
    obj.print();
    obj.pop();
    cout << "after popping ..";
    obj.print();
    cout << "After sorting ..";
    obj.sort();
    obj.print();

    return 0;
}