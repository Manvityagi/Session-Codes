class Solution {
public:
    
    int binary_search(vector<int> &nums, int target, int which){
        int n = nums.size(); 
        int lo = 0, hi = n-1;
        int res = -1;
        while(lo <= hi){
            int mid = (lo+hi)/2;
            if(nums[mid] == target){
                res = mid;
                if(which == 1){
                    hi = mid-1;
                } else {
                    lo = mid+1;
                }
            } else if(target < nums[mid]){
                hi = mid-1;
            } else {
                lo = mid+1;
            }
        }
        
        return res;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans(2,-1);
        
        ans[0] = binary_search(nums,target,1);
        ans[1] = binary_search(nums,target,2);
        
        return ans;
    }
};