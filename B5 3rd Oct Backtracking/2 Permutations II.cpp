class Solution
{
public:
  vector<vector<int> > ans;
  void helper(vector<int> &nums, vector<int> &currans, vector<int> &used)
  {
    if (currans.size() == nums.size())
    {
      ans.push_back(currans);
      return;
    }
    for (int i = 0; i < nums.size(); i++)
    {
      /*
        if used[i] = 1 or if nums[i] == nums[i-1] and 
        nums[i-1] was already 
        used to make the call, 
        we won't make another call with the same params
        (obviously we have sorted the array beforehand to make sure duplicate 
        elements occur together and we can recognize and skip duplicate calls) 
      */

      if (used[i] == 1 || (i > 0 && nums[i] == nums[i - 1] && used[i - 1] == 1))
        continue;
      
      //if we dont do used[i-1] == 1, we may end up making no calls at all, Example - [1,1,1]
      
      used[i] = 1;
      currans.push_back(nums[i]);
      helper(nums, currans, used);
      used[i] = 0;
      currans.pop_back();
    }
  }
  vector<vector<int> > permuteUnique(vector<int> &nums)
  {
    vector<int> currans = {};
    vector<int> used(nums.size(), 0);
    sort(nums.begin(), nums.end());
    helper(nums, currans, used);
    return ans;
  }
};