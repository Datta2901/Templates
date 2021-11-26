#include<bits/stdc++.h>
using namespace std;

void makeSet(int vertices,vector<int>&parent){
    for(int i = 0; i < vertices; i++){
        parent[i] = i; 
    }
}

int findParent(int node,vector<int>&parent){
    if(node == parent[node]){
        return node;
    }
    return parent[node] = findParent(parent[node],parent);
}

void Union(int u,int v,vector<int>&parent,vector<int>&rank){
    u = findParent(u,parent);
    v = findParent(v,parent);
    if(rank[u] < rank[v]){
        parent[u] = v;
    }else if(rank[v] < rank[u]){
        parent[v] = u;
    }else{
        parent[u] = v;
        rank[u]++;
    }
}

int main(){
    int vertices,edges;
    cin >> vertices >> edges;
    vector<int>rank(vertices,0);
    vector<int>parent(vertices,0);
    makeSet(vertices,parent);
    for(int i = 0; i < edges; i++){
        int u,v;
        cin >> u >> v;
        Union(u,v,parent,rank);
    }
    int queries;
    cin >> queries;
    while(queries--){
        int type,u,v;
        cin >> type >> u >> v;
        if(type == 1){
            Union(u,v,parent,rank);
        }else{
            if(findParent(u,parent) != findParent(v,parent)){
                cout << "Not belongs to the same component" << endl;
            }else{
                cout << "Belongs to the same component" << endl;
            }
        }
    }
    return 0;
}