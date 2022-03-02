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

class DSU{
    public:
      vector<int>parent,rank;
      void init(int n){
          for(int i = 0; i < n; i++){
              parent[i] = i;
          }
      }
      DSU(int n){
          parent.resize(n);
          init(n);
      }
      
      void Union(int u,int v){
          int pu = FindParent(u);
          int pv = FindParent(v);
          if(pu == pv){
              return;
          }
          else if(rank[pu] >= rank[pv]){
              parent[pv] = u;
              rank[pu]++;
          }else{
              parent[pu] = v;
              rank[pv]++;
          }
      }
      
      int FindParent(int node){
          if(parent[node] == node){
              return node;
          }
          return parent[node] = FindParent(parent[node]);
      }   
  };