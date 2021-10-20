 
class Solution {
public:
    int numDistinct(string s, string t) {
        
    int r = s.size();
    int c = t.size();
    if(r == 0) return 0; 
    vector<vector<double>> dp(r,vector<double>(c,0)); 
    
    if(s[0] == t[0]) dp[0][0] = 1;
    for(int i = 1; i < r; i++){ //filling the first col
        dp[i][0] += (dp[i-1][0] + (s[i] == t[0] ? 1 : 0));
    }
    
    for(int i = 1; i < r; i++){
        for(int j = 1; j < c && j <= i; j++){ 
            //j <= i, because t cannot be greater than s, 
            //we cannot find a longer subsequence in a shorter string
            if(s[i] == t[j]){
                dp[i][j] = (dp[i-1][j-1] + dp[i-1][j]);
            }else{
                dp[i][j] = dp[i-1][j]; 
            }
        }
    }

    return dp[r-1][c-1]; 
    }
};