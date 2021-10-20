/*
Number of connected components in a given graph

*/

class Solution {
public:
    
    vector<int> dx = {0,0,1,-1}; 
    vector<int> dy = {1,-1,0,0}; 
    
    bool valid(int x, int y, int r, int c){
        return (x >= 0 && x < r && y >= 0 && y < c);   
    }
    
    void dfs(int x, int y, vector<vector<int>> &visited, vector<vector<char>> &grid){
        int r = grid.size(), c = grid[0].size();
        if(!valid(x,y,r,c) || grid[x][y] == '0') return;
        
        visited[x][y] = 1; 
        for(int i = 0; i < 4; i++){
            int newx = x + dx[i], newy = y + dy[i]; 
            if(!valid(newx,newy,r,c) || grid[newx][newy] == '0') continue; 
            if(visited[newx][newy]) continue;
            dfs(newx,newy,visited,grid);
        }
        
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int r = grid.size(); 
        if(!r) return 0;
        int c = grid[0].size();
        int ans = 0; 
        vector<vector<int>> visited(r,vector<int>(c,0)); 
        
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                if(!visited[i][j] && grid[i][j] != '0'){
                    dfs(i,j,visited,grid);
                    ans++;
                }
            }
        }
        
        return ans; 
    }
};