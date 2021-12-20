#include<bits/stdc++.h>
using namespace std;

void dfs(int node,vector<int>adj[],stack<int> &answer,vector<int> &visited){
    visited[node] = 1;
    for(auto it : adj[node]){
        if(!visited[it]){
            dfs(it,adj,answer,visited);
        }
    }
    answer.push(node);
}

stack<int> topo(vector<int>adj[],int vertices){
    stack<int> answer;
    vector<int>visited(vertices + 1,0);
    for(int i = 0; i < vertices; i++){
        if(!visited[i]){
            dfs(i,adj,answer,visited);
        }   
    }
    return answer;
}


int main(){
    int edges,vertices;
    cin >> vertices >> edges;
    vector<int>adj[vertices + 1];
    for(int i = 0; i < edges; i++){
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    stack<int>answer = topo(adj,vertices);
    cout << "Topological sorting of Directed Acyclic Graph is : ";
    while(!answer.empty()){
        cout << answer.top() << " ";
        answer.pop();
    }
}

