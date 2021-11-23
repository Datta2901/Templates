#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    int m,n;
public: 

    bool isValid(int x,int y){
        if(x < 0 || x >= m || y < 0 || y >= n){
            return false;
        }
        return true;
    }

    void bfs(vector<vector<int> >&grid,vector<vector<bool> > &visited,vector<vector<int> >&distance){
        queue<pair<int,int>> track;
        track.push({0,0});
        int dx[2] = {1,0};
        int dy[2] = {0,1};
        visited[0][0] = true;
        distance[0][0] = grid[0][0];
        while(!track.empty()){
            int x = track.front().first;
            int y = track.front().second;
            track.pop();
            for(int i = 0; i < 2; i++){
                int X = x + dx[i];
                int Y = y + dy[i];
                if(isValid(X,Y) == false){
                    continue;
                }if(visited[X][Y] == true){
                    distance[X][Y] = min(distance[X][Y],distance[x][y] + grid[X][Y]);
                    continue;
                }
                visited[X][Y] = true;
                track.push({X,Y});
                distance[X][Y] = min(distance[X][Y],distance[x][y] + grid[X][Y]);
            }
        }
    }

    int minPathSum(vector<vector<int> >& grid) {
        m = grid.size();
        n = grid[0].size();
        // cout << m << " " << n << endl;
        vector<vector<bool> > visited(m,vector<bool>(n,false));
        vector<vector<int> > distance(m,vector<int>(n,INT_MAX));
        bfs(grid,visited,distance);
        // cout << "Distance ... " << endl;
        // for(auto it : distance){
        //     for(auto n : it){
        //         cout << n << " ";
        //     }
        //     cout << endl;
        // }
        return distance[m - 1][n - 1];
    }
};

int main(){
    Solution obj;
    int m,n;
    cin >> m >> n;
    vector<vector<int> > grid(m);
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            int a;
            cin >> a;
            grid[i].push_back(a);
        }
    }

    cout << obj.minPathSum(grid);
    
    return 0;
}