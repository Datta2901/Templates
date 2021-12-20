#include<bits/stdc++.h>
using namespace std;


void dijkstra(vector<pair<int,int> > adj[],vector<int>&distance,int source){
    // priority_queue<int,int> - maxPriority queue by default syntax
    // priority_queue<int,int,vector<int>,greater<int>)-min Priority queue syntax
    priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >track;
    // distance, node;
    distance[source] = 0;
    track.push({0,source});
    while(!track.empty()){
        int node = track.top().second;
        int nodeDis = track.top().first;
        track.pop();
        for(auto it : adj[node]){
            if(nodeDis + it.second < distance[it.first]){
                distance[it.first] = nodeDis + it.second;
                track.push({distance[it.first],it.first});
            }
        }
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
    
    dijkstra(adj,distance,0);

    for(auto i : distance){
        cout << i << " ";
    }
    cout << endl;

    return 0;
}

