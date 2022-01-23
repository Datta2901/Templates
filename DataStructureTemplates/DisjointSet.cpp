// disjointset union by size
#include<bits/stdc++.h>
using namespace std;

class DSU{
    private:
        vector<int>parent,size;
    public:
        DSU(int n){
            for(int i = 0; i < n; i++){
                parent.push_back(i);
                size.push_back(1);
            }
        }
        void Union(int u,int v){
            int parU = findParent(u);
            int parV = findParent(v);
            if(parU == parV){
                return ;
            }

            if(size[parU] < size[parV]){
                parent[parU] = parV;
                size[parV] += size[parU];
            }else{
                parent[parV] = parU;
                size[parU] += size[parV];
            }
        }

        int findParent(int node){
            if(parent[node] == node){
                return node;
            }
            return parent[node] = findParent(parent[node]);
        }
};

// disjointset union by Rank

class DSURank{
    private:
        vector<int>parent,rank;
    public:
        DSURank(int n){
            for(int i = 0; i < n; i++){
                parent.push_back(i);
                rank.push_back(1);
            }
        }
        void Union(int u,int v){
            int parU = findParent(u);
            int parV = findParent(v);
            if(parU == parV){
                return ;
            }
            if(rank[parU] == rank[parV]){
                parent[parV] = parU;
                rank[parV]++;
            }
            if(rank[parU] == rank[parV]){
                parent[parU] = parV; 
            }else{
                parent[parV] = parU;
                rank[parU] += 1;
            }
        }

        int findParent(int node){
            if(parent[node] == node){
                return node;
            }
            return parent[node] = findParent(parent[node]);
        }
}
