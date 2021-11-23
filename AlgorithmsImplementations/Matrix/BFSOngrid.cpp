#include<bits/stdc++.h>
using namespace std;

class Solution{
    private:
        int maximum = 0;
    public:
        void bfs(vector<vector<int> >& grid,int i,int j){
            int count = 0;
            int row = grid.size();
            int col = grid[0].size();
            queue<pair<int,int> >track;
            track.push({i,j});
            grid[i][j] = 2;
            int dx[4] = {0,0,1,-1};
            int dy[4] = {1,-1,0,0};
            while(!track.empty()){
                int X = track.front().first;
                int Y = track.front().second;
                track.pop();
                for(int i = 0; i < 4; i++){
                    int x = X + dx[i];
                    int y = Y + dy[i];
                    if((x < 0 || x >= row) || (y < 0 ||y >= col) ||  grid[x][y] == 0 || grid[x][y] == 2){
                        continue;
                    } 
                    grid[x][y] = 2;
                    count++;
                    track.push({x,y});
                }
            }
            maximum = max(maximum,count);
        }

        int maxAreaOfIsland(vector<vector<int> >& grid) {
            int row = grid.size();
            int col = grid[0].size();
            int maxi = INT_MIN;
            for(int i = 0; i < row; i++){
                for(int j = 0; j < col; j++){
                    if(grid[i][j] != 0){
                        bfs(grid,i,j);
                    }
                }
            }
            return maximum;
        }
};


int main(){
    Solution obj;
    vector<int>num;
    int size;
    cin >> size;
    for(int i = 0; i < size; i++){
        int a;
        cin >> a;
        num.push_back(a);
    }
    return 0;
}