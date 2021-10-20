//Approach 1
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
      for (int i = 0; i < nums.size(); i++) //exploring which value to keep in curr_ans
    {
      if (used[i] == 1) //if already in curr_ans
           continue;
      used[i] = 1;
      currans.push_back(nums[i]);
      helper(nums, currans, used);
      used[i] = 0;
      currans.pop_back();
    }
  }
  vector<vector<int> > permute(vector<int> &nums)
  {
    vector<int> currans = {};
    vector<int> used(nums.size(), 0);

    helper(nums, currans, used);
    return ans;
  }
};

//Approach 2
class Solution
{
public:
  vector<vector<int> > ans;
  void helper(vector<int> &nums, vector<int> &currans)
  {
    if (currans.size() == nums.size())
    {
      ans.push_back(currans);
      return;
    }
      for (int i = 0; i < nums.size(); i++)
    {
      if (nums[i] == INT_MAX)
           continue;
      int orig = nums[i];

      currans.push_back(nums[i]);
      nums[i] = INT_MAX;

      helper(nums, currans);

      nums[i] = orig;
      currans.pop_back();
    }
  }
  vector<vector<int> > permute(vector<int> &nums)
  {
    vector<int> currans = {};
    helper(nums, currans);
    return ans;
  }
};

//Approach 3
class Solution
{
public:
  vector<vector<int> > ans;

  void helper(vector<int> &nums, int curr_idx)
  {
    int n = nums.size();
    if (curr_idx == n)
      ans.emplace_back(nums);

    for (int j = curr_idx; j < n; j++)
    {
      swap(nums[curr_idx], nums[j]);
      helper(nums, curr_idx + 1);
      swap(nums[curr_idx], nums[j]);
    }
  }

  vector<vector<int> > permute(vector<int> &nums)
  {
    helper(nums, 0);
    return ans;
  }
};