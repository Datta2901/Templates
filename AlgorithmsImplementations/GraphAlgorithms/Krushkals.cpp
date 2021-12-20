#include<bits/stdc++.h>
using namespace std;

struct node{
    int u;
    int v;
    int w;
    node(int uu,int vv,int wt){
        u = uu;
        v = vv;
        w = wt;
    }
};

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



bool comp(node a,node b){
    return a.w < b.w;
} 


int main(){
    int vertices,e;
    cin >> vertices >> e;
    vector<int>rank(vertices,0);
    vector<int>parent(vertices,0);
    vector<pair<int,int> > Mst;
    makeSet(vertices,parent);
    vector<node> edges;
    vector<tuple<int,int,int> > answer;
    for(int i = 0; i < e; i++){
        int u,v,w;
        cin >> u >> v >> w;
        edges.push_back(node(u,v,w));
    }
    sort(edges.begin(),edges.end(),comp);
    int cost = 0;
    for(auto it : edges){
        if(findParent(it.u,parent) != findParent(it.v,parent)){
            cost += it.w;
            answer.push_back(tuple<int,int,int>(it.u,it.v,it.w));
            Mst.push_back({it.u,it.v});
            Union(it.u,it.v,parent,rank); 
        }
    }

    cout << cost << endl;
    
    for(auto it : answer){
        cout << get<0>(it) << " <-> " << get<1>(it) << " : " << get<2>(it) << endl;
    }
    return 0;
}