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