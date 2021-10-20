/*
dp[i][j] = Minimum Power required from i,j to r-1,c-1

Power required in current movement/position = Next Step Power Required - Current Powerup

We are trying to find minHP at [0][0]; this is the end goal. 
The base case occurs at [m -1][n - 1], 
so DP must begin there and work its way to the end goal. 

*/

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& arr) {
        int r = arr.size();
        if(!r) return 0;
        int c = arr[0].size();
        vector<vector<int>> dp(r,vector<int>(c,0));
        //dp[i][j] = i,j se r-1,c-1 tak kitna power chahiye
        dp[r-1][c-1] = arr[r-1][c-1] >= 0 ? 1 : abs(arr[r-1][c-1]-1);
        
        //fill last row
        for(int i = c-2; i >= 0; i--)
              dp[r-1][i] = max(1,dp[r-1][i+1] - arr[r-1][i]);            
            
        
        //fill last col
        for(int i = r-2; i >= 0; i--)
            dp[i][c-1] = max(1,dp[i+1][c-1] - arr[i][c-1]);
        
        for(int i = r-2; i >= 0; i--){
            for(int j = c-2; j >= 0; j--){
                int right = max(1,dp[i][j+1] - arr[i][j]);
                int down = max(1,dp[i+1][j] - arr[i][j]);
                dp[i][j] = min(right,down);
            }
        }

        return dp[0][0];
    }
};