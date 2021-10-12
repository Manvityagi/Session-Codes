class Solution {
public:
    vector<int> dx = {0,0,1,-1};
    vector<int> dy = {1,-1,0,0};
    
    bool valid(int x, int y, int r, int c){
        return x >= 0 && y >= 0 && x < r && y < c; 
    }
    

    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int r = matrix.size(),x,y;
        if(!r) return {};
        int c = matrix[0].size();
        vector<vector<int>> dis(r, vector<int>(c,INT_MAX));
        queue<pair<int,int>> q;
        
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                if(matrix[i][j] == 0){
                    dis[i][j] = 0; 
                    q.emplace(i,j);
                }
            }
        }
        
        while(!q.empty()){
            tie(x,y) = q.front(); 
            q.pop();

            for(int i = 0; i < 4; i++){
                int newx = x + dx[i];
                int newy = y + dy[i];
                if(!valid(newx,newy,r,c) || dis[newx][newy] != INT_MAX) continue; 
                dis[newx][newy] = dis[x][y] + 1; 
                q.emplace(newx,newy);
            }
        }
        return dis; 
    }
};