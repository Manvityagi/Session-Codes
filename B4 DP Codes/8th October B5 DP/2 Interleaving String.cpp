/*
    TC - O(m*n)
    SC - O(m*n)
*/
class Solution {
public:
    bool helper(string s1, int i, string s2, int j, string s3, int k, vector<vector<int>> &dp){
        if(i == s1.size()){
            return s2.substr(j) == s3.substr(k);
        }
        if(j == s2.size()){
            return s1.substr(i) == s3.substr(k);
        }
        
        if(dp[i][j] != -1) return dp[i][j];
        bool ans = 0;
        if((s3[k] == s1[i] && helper(s1,i+1,s2,j,s3,k+1,dp)) || 
            (s3[k] == s2[j] && helper(s1,i,s2,j+1,s3,k+1,dp))
          ) return dp[i][j] = 1;
        
        return dp[i][j] =  0;
    }
    
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size(), m = s2.size(), t = s3.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        if(n+m != t) return 0;
        return helper(s1,0,s2,0,s3,0,dp);
        
    }
};