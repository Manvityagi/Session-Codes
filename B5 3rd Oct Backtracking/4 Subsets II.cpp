class Solution {
public:
    vector<vector<int>> ans;
    
    void subsets(vector<int> nums, int start, vector<int> currset){ 
        ans.push_back(currset)
        //base case
        if(start == nums.size()){
            return;
        }   
       for(int j = start; j < nums.size(); j++){
           //just add this and sort array for avaoiding duplicates
           if (i > start && nums[i] == nums[i - 1])
                continue;
            currset.push_back(nums[j]);
            subsets(nums,j+1,currset);
            currset.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        subsets(nums,0,{});
        return ans;
    }
};