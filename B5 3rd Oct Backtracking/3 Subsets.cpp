//Approach 1 - Recursive
/*
    Take example of [1,2,3].
                            ([ans],[nums])
                              ([],[1,2,3])
         (choose 1)  /                           \ (don't choose 1)
                    /                             \
              ([1],[2,3])                         ([],[2,3])
      (choose 2)/        \(No 2)            (choose 2)/ \(No 2)    
               /          \                         /   \
       ([1,2],[3])         ([1],[3])          ([2],[3])   ([],[3])
(choose 3)/      \(No 3) 
         /        \
  ([1,2,3],[])  ([1,2],[]) ([1,3],[]) ([1,3],[]).......

(Base cases when nums is empty)


*/
class Solution {
public:
    vector<vector<int>> ans;
    void subsets(vector<int>& nums, vector<int> &currset, int curr_idx){
       
        //base case
        if(curr_idx == nums.size()){
            ans.push_back(currset);
            return;
        }
        
        
        //2 choices for curr element
        
        //choice 1 : keep it in currans
        currset.push_back(nums[curr_idx]);
        subsets(nums,currset,curr_idx+1);
        
        //choice 2 : Don't keep it in currans
        currset.pop_back();
        subsets(nums,currset,curr_idx+1);
            
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> currans = {};
        
        subsets(nums,currans,0);
        
        return ans;
    }
};

/* 
    Approach 2 - 
    For each element in nums, I will push back the current number into my 
    current set (`currset`) and then ask recursion to work on the
    sets starting from this current number and then backtrack by popping
    back the current number.

*/

//change this for subsets II
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
        //    if (i > start && nums[i] == nums[i - 1])
        //         continue;
            currset.push_back(nums[j]);
            subsets(nums,j+1,currset);
            currset.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        subsets(nums,0,{});
        return ans;
    }
};


//Approach 3 - Iterative
/*
    Using [1, 2, 3] as an example, the iterative process is like:
    Initially, one empty subset [[]]
    Adding 1 to []: [[], [1]];
    Adding 2 to [] and [1]: [[], [1], [2], [1, 2]];
    Adding 3 to [], [1], [2] and [1, 2]: [[], [1], [2], [1, 2], [3], [1, 3], [2, 3], [1, 2, 3]].
*/

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans= {{}};
        for (int num : nums) {
            int n = ans.size();
            for (int i = 0; i < n; i++) {
                ans.push_back(ans[i]); 
                ans.back().push_back(num);
            }
        }
        return ans;
    }
};