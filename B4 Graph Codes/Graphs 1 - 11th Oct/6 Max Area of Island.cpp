class Solution {
    int r, c;
    int dfs(int i, int j, vector<vector<int>>& grid, vector<vector<bool>>& visited, int ans){
         if(i < 0 || j < 0 || i >= r || j >= c || grid[i][j] == 0 || visited[i][j]) return ans;
        
        visited[i][j] = true;
        return 1 +
            dfs(i,j+1,grid,visited,ans) + 
            dfs(i+1,j,grid,visited,ans) +
            dfs(i-1,j,grid,visited,ans) + 
            dfs(i,j-1,grid,visited,ans);
        
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        r = grid.size();
        if(r == 0) return 0;
        c = grid[0].size();
        vector<vector<bool>> visited(r,vector<bool>(c,false));
        
        int max_area = 0;
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                if(!visited[i][j] && grid[i][j] == 1){
                    int curr = dfs(i,j,grid,visited,0);
                    max_area = max(max_area,curr);
                }
            }
        }
        
        return max_area;
    }
};