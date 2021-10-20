//Approach 1

class Solution {
public:
    vector<vector<int>> ans;
    
    void helper(int pos, vector<int> &nums, vector<int> currans, int currSum, int target){
        if(currSum == target){
            ans.emplace_back(currans);
            return;
        }
        if(currSum > target) return; 
        
        for(int i = pos; i < nums.size(); i++){
            currans.emplace_back(nums[i]); 
            helper(i,nums,currans,currSum+nums[i],target);
            currans.pop_back();
        }
    }
    
     
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        helper(0,candidates,{},0,target);
        return ans; 
    }
};
