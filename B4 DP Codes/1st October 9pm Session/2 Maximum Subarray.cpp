/*

dp[i] means the largest sum among the subarrays whose last element is A[i].
int max = A[0]; dp[0] = A[0]; 
	for (int i = 1; i < A.length; i++) {			
		dp[i] = Math.max(dp[i-1] + A[i] ,A[i]);
		max = Math.max(max, dp[i]);
	}
	return max;


//Space optimization
The basic idea is to check previous sum, reset it to 0 if it's less than 0.
A negative sum will never be carried forward because it will alwasy decrease our sum

*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_ending_here = 0, max_till_now = nums[0];
        int n = nums.size(); 
        for(int i = 0; i < n; i++){
            max_ending_here += nums[i]; 
            max_till_now = max(max_till_now,max_ending_here); 
            max_ending_here = max(0,max_ending_here);
        }
        return max_till_now; 
    }
};