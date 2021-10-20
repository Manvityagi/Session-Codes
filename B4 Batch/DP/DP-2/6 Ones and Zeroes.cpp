// This is a classical 0-1 knapsack Problem.

class Solution {
public:
    int dp[601][101][101]; 

    int helper(int pos, vector<string> &strs, int m, int n){
        
        if(m < 0 || n < 0) return 0;
        
        if(pos >= strs.size()) return 0; 
        if(dp[pos][m][n] != -1) return dp[pos][m][n]; 
        
        //don't take strs[pos] 
        int op1 = helper(pos+1,strs,m,n),op2 = 0; 
        
        int newm = m, newn = n;
        for(auto c : strs[pos]){
            if(c=='0') newm--;
            else newn--; 
        }
        
        if(newm >= 0 && newn >= 0){
            op2 = 1 + helper(pos+1,strs,newm,newn);
        }
        
        dp[pos][m][n] = max(op1,op2); 
        return dp[pos][m][n]; 
    }
    
    int findMaxForm(vector<string>& strs, int m, int n) {
        memset(dp,-1,sizeof(dp)); 
        return helper(0,strs,m,n);
    }
};