#include<bits/stdc++.h>
using namespace std;



// DFS iterative implementation 
// here nodes are starting with indexing 1
vector<int> DFS(int vertices,vector<int> adj[]){
    vector<int>answer;
    vector<bool> visited(vertices + 1,false);
    stack<int> track;
    
    for(int i = 1; i <= vertices; i++){
        if(!visited[i]){
            visited[i] = true;
            track.push(i);
            while(!track.empty()){
                int temp = track.top();
                track.pop();
                answer.push_back(temp);
                for(auto i : adj[temp]){
                    if(!visited[i]){
                        track.push(i);
                        visited[i] = true;
                    }
                }
            }
        }
    }
    return answer;
}

//DFS recursive implementation
void DFSRecursive(int curr,vector<bool>& visited,vector<int> adj[],vector<int>& answer){
    answer.push_back(curr);
    visited[curr] = true;
    for(auto it : adj[curr]){
        if(!visited[it]){
            DFSRecursive(it,visited,adj,answer);
        }
    }
}   

int main(){
    int vertices,edges;
    cout << "Enter the vertices and edges of the graph respectively " << endl;
    cin >> vertices >> edges;
    vector<int> adj[vertices + 1],answer; // one based indexing
    cout << "Enter the edges of the graph" << endl;
    for(int i = 1; i <= edges; i++){
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cout << "Adjacency list of given graph is " << endl;
    for(int i = 0; i <= vertices; i++){
        cout << i << " : ";
        for(auto j : adj[i]){
            cout << j << " ";
        }
        cout << endl;
    }


    answer = DFS(vertices,adj);
    
    cout << "DFS of the given graph is " << endl;
    for(auto i : answer){
        cout << i << " ";
    }
    cout << endl;

    answer.clear();

    cout << "------------------------------------" << endl;
    cout << "DFS recursive implementation " << endl;
    
    vector<bool> visited(vertices + 1,false);
    for(int i = 1; i <= vertices; i++){
        if(!visited[i]){
            DFSRecursive(i,visited,adj,answer);
        }
    }

    for(auto i : answer){
        cout << i << " ";
    }
    cout << endl;

    return 0;

    /* 
        Similar to bfs 
        Time complexity of BFS will be O(n + E)
        Time for visiting n nodes and e for visiting adjacent nodes in Adjacency list

        Space Complexity will be O(N + E)       + O(N)      +  O(N)
                                Adjacency list    visited     Stack    
    */
}



