class Solution {
public:
    
    int LIS(vector<int>& a){
        int n = a.size(); 
        vector<int> dp(n,1); 
        int mx = 1; 
        for(int i = 1; i < n; i++){
            for(int j = i-1; j >= 0; j--){
                if(a[j] < a[i]){
                    dp[i] = max(dp[i],1+dp[j]); 
                }
            }
            mx = max(mx,dp[i]); 
        }
        return mx;
    }
    
    static bool comp(const pair<int,int> &a, const pair<int,int> &b){
        if(a.first == b.first) return a.second > b.second; //so that LIS doesnt include width if its same 
        return a.first < b.first; //this will put smaller number first -> increasing order
    }
    
    int maxEnvelopes(vector<vector<int>>& e) {
        int n = e.size(); 
        if(n == 0) return 0;
        //width, height
        vector<pair<int,int>> arr; 
        for(int i = 0; i < n; i++){
            arr.emplace_back(e[i][0],e[i][1]); 
        }
        //sorted by increasing order on width
        sort(arr.begin(),arr.end(),comp);
        vector<int> a; 
        for(int i = 0; i < n; i++){
            a.emplace_back(arr[i].second); 
        }
        
        int ans = LIS(a); 
        return ans;
    }
};