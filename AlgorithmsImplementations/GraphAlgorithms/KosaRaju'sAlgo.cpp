#include<bits/stdc++.h>
using namespace std;

void dfs(vector<int>adj[],vector<bool>&visited,int source,stack<int>&answer){
    visited[source] = true;
    for(auto it : adj[source]){
        if(!visited[it]){
            dfs(adj,visited,it,answer);
        }
    }
    answer.push(source);
}

stack<int> topo(vector<int>adj[],int vertices,vector<bool>&visited){
    stack<int>answer;
    for(int i = 0; i < vertices; i++){
        if(!visited[i]){
            dfs(adj,visited,i,answer);
        }
    }
    return answer;
}


void RevDfs(vector<int>rev[],vector<bool>&visited,int source){
    cout << source << " ";
    visited[source] = true;
    for(auto it : rev[source]){
        if(!visited[it]){
            RevDfs(rev,visited,it);
        }
    }
}

int main(){
    int edges,vertices;
    cin >> vertices >> edges;
    vector<int>adj[vertices],rev[vertices];
    for(int i = 0; i < edges; i++){
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    vector<bool>visited(vertices,false);
    stack<int>topoAnswer = topo(adj,vertices,visited);

    for(int i = 0; i < vertices; i++){
        visited[i] = false;
        for(auto it : adj[i]){
            rev[it].push_back(i);
        }   
    }

    cout << "Strongly Connected Components are : " << endl;;
    while(!topoAnswer.empty()){
        int node = topoAnswer.top();
        topoAnswer.pop();
        if(!visited[node]){
            RevDfs(rev,visited,node);
            cout << endl;
        }
    }
    return 0;    
}



