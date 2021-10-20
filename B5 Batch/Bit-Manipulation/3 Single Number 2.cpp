/*
9 11 9 11 9 11 5

9  = 1 0 0 1
11 = 1 0 1 1
5 =  0 1 0 1

*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int> freq(32,0);

        for(auto num : nums){
            for(int i = 0; i < 32; i++){
                //if ith bit is set
                if(1<<i & num) freq[i]++;
            }
        }
        
        int ans = 0;
        for(int i = 0; i < 32; i++){
            if(freq[i]%3){
                ans += (1<<i);
            }
        }
        return ans;
    }
};