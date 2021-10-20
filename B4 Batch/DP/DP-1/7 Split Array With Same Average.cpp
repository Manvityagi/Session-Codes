//Approach 1: Recursive - TLE - n * 2^n

class Solution
{
public:
    //Time Complexity: Exponential - It may try each possible subset
    bool targetSumSubarray(vector<int> &nums, int curr_idx, int curr_size, int target)
    {
        if (curr_size == 0)
            return target == 0;
        if (curr_idx >= nums.size())
            return 0;

        //add current element
        if (target - nums[curr_idx] > 0 || curr_size > 0)
            if (targetSumSubarray(nums, curr_idx + 1, curr_size - 1, target - nums[curr_idx]))
                return 1;

        //dont add current element
        if (targetSumSubarray(nums, curr_idx + 1, curr_size, target))
            return 1;

        return 0;
    }

    bool splitArraySameAverage(vector<int> &nums)
    {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int n = nums.size();

        for (int n1 = 1; n1 <= n / 2; n1++)
        {
            if ((sum * n1) % n)
                continue;

            int target = (sum * n1) / n;

            if (targetSumSubarray(nums, 0, n1, target))
                return 1;
        }

        return 0;
    }
};

//Approach 2: n^2 * Sum(array): 30*30 * 30*10^4 = 27*10^7 Strict Time Limit
/*

Varying parameters - 
    curr_idx = O(n)
    curr_size = O(n) ; n/2
    target     = Sum
    
*/

class Solution
{
public:
    bool targetSumSubarray(vector<int> &nums, int curr_idx, int curr_size, int target, vector<vector<vector<int> > > &dp)
    {
        if (curr_size == 0)
            return (target == 0);

        if (curr_idx >= nums.size() || target < 0 || curr_size < 0)
            return 0;

        int &val = dp[curr_idx][curr_size][target];
        if (val != -1)
            return val;

        //add current element
        if (targetSumSubarray(nums, curr_idx + 1, curr_size - 1, target - nums[curr_idx], dp))
            return val = 1;

        //dont add current element
        if (targetSumSubarray(nums, curr_idx + 1, curr_size, target, dp))
            return val = 1;

        return val = 0;
    }

    bool splitArraySameAverage(vector<int> &nums)
    {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int n = nums.size();

        for (int n1 = 1; n1 <= n / 2; n1++)
        {
            if ((sum * n1) % n)
                continue;
            int target = (sum * n1) / n;

            vector<vector<vector<int> > > dp(n + 1, vector<vector<int> >(n + 1, vector<int>(sum + 1, -1)));
            if (targetSumSubarray(nums, 0, n1, target, dp))
                return 1;
        }

        return 0;
    }
};
