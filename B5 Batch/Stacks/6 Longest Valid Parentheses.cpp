class Solution {
public:
    int longestValidParentheses(string A) {
        int n = A.size(); 
        stack<pair<char,int>> st;
        vector<int> ans(n,0); 
        int mx = 0; 
        for(int i = 0; i < n; i++){
        if(A[i] == '('){
            st.emplace(A[i],i); 
        } else {
             if(!st.empty()){
                 auto top = st.top(); 
                 int diff = i - top.second + 1;
                 if(top.second >= 1) ans[i] = diff+ans[top.second-1];
                 else ans[i] = diff;
                 mx = max(mx,ans[i]);
                 st.pop();
             }
        }
    }
        for(auto &e : ans) cout << e << " ";
        
        return mx; 
    }
};