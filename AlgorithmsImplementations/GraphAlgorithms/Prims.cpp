#include<bits/stdc++.h>
using namespace std;

void PrimsBruteForce(vector<pair<int,int>> adj[],int vertices,vector<int>&distance,int source){
    vector<int>parent(vertices,0);
    vector<bool> Mst(vertices,false);
    distance[source] = 0;
    parent[source] = -1;
    for(int i = 0; i < vertices - 1; i++){
        int mini = INT_MAX,index;
        for(int j = 0; j < vertices; j++){
            if(mini > distance[j] && Mst[j] == false){
                mini = distance[j];
                index = j;
            }
        }
        Mst[index] = true;
        for(auto it : adj[index]){
            int v = it.first;
            int weight = it.second;
           if(weight < distance[v] && Mst[v] == false){
               distance[v] = weight;
               parent[v] = index;
           } 
        } 
    }
}


void Prims(vector<pair<int,int>> adj[],int vertices,vector<int>&distance,int source){
    vector<int>parent(vertices,0);
    vector<bool> Mst(vertices,false);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int> > > track;
    distance[source] = 0;
    Mst[source] = true;
    parent[source] = -1;
    track.push({distance[source],source});
    while(!track.empty()){
        int index = track.top().second;
        track.pop();
        Mst[index] = true;
        for(auto it : adj[index]){
            int v = it.first;
            int weight = it.second;
           if(weight < distance[v] && Mst[v] == false){
               distance[v] = weight;
               parent[v] = index;
               track.push({distance[v],v}); 
           } 
        } 
    }

    for(int i = 1; i < vertices; i++){
        cout << parent[i] << " -> " << i << " -> " << distance[i] << endl;
    }
}



int main(){
    int edges,vertices;
    cin >> vertices >> edges;
    vector<pair<int,int> >adj[vertices];
    vector<int>distance(vertices,INT_MAX);
    for(int i = 0; i < edges; i++){
        int u,v,w;
        cin >> u >> v >> w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    
    // PrimsBruteForce(adj,vertices,distance,0);
    Prims(adj,vertices,distance,0);

    cout << "Minimum Distances : ";
    for(auto i : distance){
        cout << i << " ";
    }
    cout << endl;
    return 0;
}

