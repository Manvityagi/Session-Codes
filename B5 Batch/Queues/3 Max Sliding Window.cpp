class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size(); 
        deque<pair<int,int>> dq; 
        vector<int> ans;
        for(int i = 0; i < n; i++){
            if(dq.size() && dq.front().second < i) dq.pop_front(); 
            while(dq.size() && dq.back().first < nums[i]) dq.pop_back(); 
            
            dq.emplace_back(nums[i],i+k-1);
            
            if(i >= k -1){
                ans.emplace_back(dq.front().first); 
            }
        }
        
        return ans; 
    }
};