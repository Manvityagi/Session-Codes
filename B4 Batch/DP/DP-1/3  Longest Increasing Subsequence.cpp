//N^2
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> LIS(n,1);
        int ans = 0;
        //LIS[i] = LIS ending at ith index
        
        for(int i = 0; i < n; i++){
            for(int j = i-1; j >= 0; j--){
                if(nums[j] < nums[i]){
                    LIS[i] = max(LIS[i],1+LIS[j]);
                }
            }
            ans = max(ans,LIS[i]);
        }
        
        return ans;
    }
};

//NlogN
//2 5 3 7 11 9 10 13 6 8 10 12
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> lis;
        int n = nums.size();
        lis.push_back(nums[0]);
        
        for(int i = 1; i < n; i++){
            if(lis.back() < nums[i]) lis.push_back(nums[i]);
            else {
                //maintaining minimum number possbile on end at each index
                int just_greater_idx = lower_bound(lis.begin(),lis.end(),nums[i]) - lis.begin();
                lis[just_greater_idx] = nums[i];
            }
        }
    
        return lis.size();
        
    }
};