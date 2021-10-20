class Solution {
public:
    vector<vector<string>> res;
    void checkPal(string &s, vector<vector<int>> &isPal)
    {
        int n = s.size();
        for(int gap = 0; gap < n; gap++){
            for(int i = 0, j = i + gap; i < n, j < n; i++,j++){
                if(gap == 0){
                    isPal[i][j] = 1;
                }
                else if(s[i] == s[j] && (i == j-1 || isPal[i+1][j-1])){
                    //i == j-1 meaning gap == 1, take aa example
                    isPal[i][j] = 1;
                }
            }
        }
    }
    
    void helper(string &s,vector<vector<int>> &isPal, int l, int r, vector<string> &curr_ans){
        if(l > r) {
            res.push_back(curr_ans); 
            return; 
        }
        for(int i = l; i <= r; i++){
            if(isPal[l][i]){
                curr_ans.push_back(s.substr(l,i-l+1));
                helper(s,isPal,i+1,r,curr_ans);
                curr_ans.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        res.clear(); 
        int n = s.size();
        vector<vector<int>> isPal(n, vector<int>(n,0)); 
        checkPal(s,isPal);
        vector<string> curr_ans = {};
        helper(s,isPal,0,n-1,curr_ans);
        return res; 
    }
};