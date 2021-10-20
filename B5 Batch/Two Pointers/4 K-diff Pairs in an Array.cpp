//App 1 - Check every pair O(n^2)

//App 2 - Sort and binary search O(nlogn)

/* App 3
    Hashmap
    TC - O(n)
    SC - O(n)
*/
class Solution
{
public:
    int findPairs(vector<int> &nums, int k)
    {
        unordered_map<int, int> freq;
        int ans = 0;
        for (int num : nums)
        {
            if (k == 0)
            {
                if (freq[num] == 1)
                    ++ans; // only count once
            }
            else if (freq.find(num) == freq.end())
            { // only count when the first time n appears
                if (freq.find(num - k) != freq.end())
                    ++ans;
                if (freq.find(num + k) != freq.end())
                    ++ans;
            }
            freq[num]++;
        }
        return ans;
    }
};

/* App 4

    Two Pointer Approach
    TC - O(nlogn)
    SC - O(1)
*/
class Solution
{
public:
    int findPairs(vector<int> &arr, int k)
    {
        sort(arr.begin(), arr.end());
        int l = 0, n = arr.size(), count = 0;
        int r = 0;
        while (r < n)
        {
            if (arr[r] - arr[l] == k)
            {
                if (l == r) //if target == 0, if we dont do this, we will count extra things
                {
                    r++;
                }
                else
                {
                    count++;
                    while (l + 1 < n && arr[l] == arr[l + 1])
                        l++;
                    while (r + 1 < n && arr[r] == arr[r + 1])
                        r++;
                    l++;
                    r++;
                }
            }
            else if (arr[r] - arr[l] > k)
                l++;
            else
                r++;
        }
        return count;
    }
};
 