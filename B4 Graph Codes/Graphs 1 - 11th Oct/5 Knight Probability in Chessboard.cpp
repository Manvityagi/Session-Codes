class Solution {
public:
    
    vector<int> dx = { 2, 1, -1, -2, -2, -1, 1, 2 }; 
    vector<int> dy = { 1, 2, 2, 1, -1, -2, -2, -1 }; 
    
    double helper(vector<vector<vector<double>>> &dp, int N, int K, int r, int c){
        // cout << "working on " << r << " " << c << " " << K << "\n"; 
        if(K == 0){
            dp[r][c][K] = 1; 
            return 1; 
        }
        
        if(dp[r][c][K] != -1) return dp[r][c][K]; 
        
        dp[r][c][K] = 0; 
        for(int d = 0; d < 8; d++){
            int newr = r + dx[d], newc = c + dy[d]; 
            if(newr < 0 || newr >= N|| newc < 0 || newc >= N) continue; 
            // cout << newr << " " << newc << "\n"; 
            double temp = helper(dp,N,K-1,newr,newc);
            // cout << temp << "\n"; 
            dp[r][c][K] += (double(1.0/8) * temp);  
        }
        
        return dp[r][c][K]; 
        
    }
    
    double knightProbability(int N, int K, int r, int c) {
        vector<vector<vector<double>>> dp(N+1,vector<vector<double>>(N+1,vector<double>(K+1,-1))); 
        double ans = helper(dp,N,K,r,c); 
        // for(int i = 0; i <= N; i++){
        //     for(int j =  0; j <= N; j++){
        //         for(int k = 0; k <= K; k++){
        //             cout << dp[i][j][k] << " ";
        //         }
        //         cout << "\n"; 
        //     }
        //     cout << "\n";
        // }
        return ans; 
    }
};