#define pii pair<int, int>
#define F first
#define S second
class Solution
{
public:
    vector<int> dx = {0,0,1,-1};
    vector<int> dy = {1,-1,0,0};
    int orangesRotting(vector<vector<int>> &grid)
    {  
        int r = grid.size(), x, y, inf = 1e8;
        if (r == 0)
            return 0;
        int c = grid[0].size();
        vector<vector<int>> visited(r, vector<int>(c, 0));
        vector<vector<int>> time(r, vector<int>(c, inf));
        queue<pair<int, int>> q;
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (grid[i][j] == 2)
                {
                    q.emplace(i, j);
                    visited[i][j] = 1;
                    time[i][j] = 0; 
                } else if(grid[i][j] == 0){
                    time[i][j] = 0;
                }
            }
        }
        
        while (!q.empty())
        {
            tie(x, y) = q.front();
            q.pop();
            for (int d = 0; d < 4; d++)
            {
                int newx = x + dx[d], newy = y + dy[d];
                if (newx < 0 || newx >= r || newy < 0 || newy >= c) continue;
                if (visited[newx][newy] || grid[newx][newy] == 0) continue;
                visited[newx][newy] = 1;
                time[newx][newy] = time[x][y] + 1; 
                q.emplace(newx, newy);
            }
        }
        int max_time = 0; 
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                max_time = max(max_time,time[i][j]);
            }
        }
        if(max_time == inf) return -1;
        return max_time;
    }
};