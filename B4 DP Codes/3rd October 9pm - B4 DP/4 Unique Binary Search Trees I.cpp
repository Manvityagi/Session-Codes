/**
 * Taking 1~n as root respectively:
 *      1 as root: # of trees = F(0) * F(n-1)  // F(0) == 1
 *      2 as root: # of trees = F(1) * F(n-2) 
 *      3 as root: # of trees = F(2) * F(n-3)
 *      ...
 *      n-1 as root: # of trees = F(n-2) * F(1)
 *      n as root:   # of trees = F(n-1) * F(0)
 *
 * So, the formulation is:
 *      F(n) = F(0) * F(n-1) + F(1) * F(n-2) + F(2) * F(n-3) + ... + F(n-2) * F(1) + F(n-1) * F(0)
 */

//Recursive Solution
class Solution {
public:
    int numTrees(int n) {
        if(n == 0 || n == 1) return 1;
        
        int res = 0;
        for(int i = 0; i < n; i++){
            res += (numTrees(i) * numTrees(n-i-1));
        }
        return res;
    }
};


//Memoized Solution - Top Down
class Solution {
public:
    
    int helper(int n, vector<int> &dp){
        if(dp[n] != -1) return dp[n];
        
        int res = 0;
        for(int i = 0; i < n; i++){
            int left = dp[i] == -1 ? helper(i,dp) : dp[i];
            int right = dp[n-i-1] == -1 ? helper(n-i-1,dp) : dp[n-i-1];
            
            res += (left*right);
        }
        
        dp[n] = res;
        return res;
    }
    
    int numTrees(int n) {
       vector<int> dp(n+1,-1);
       dp[0] = 1, dp[1] = 1;
       return helper(n,dp);
    }
};

//Bottom Up Solution
class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n+1);
        dp[0] = 1;
        dp[1] = 1;
        
        for(int i = 2; i <= n; i++){
            dp[i] = 0;
            for(int j = 1; j <= i; j++){
                dp[i] += (dp[i-j]*dp[j-1]);
            }
        }
        return dp[n];
    }
};