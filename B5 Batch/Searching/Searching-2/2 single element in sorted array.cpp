class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        int st = 0, end = n-1;
        
        while(st <= end){
            int mid = (st+end)>>1;
            if((mid && nums[mid-1] == nums[mid]) || (mid < n && nums[mid] == nums[mid+1])){
                //its not the answer
                
                int check = mid;
                if(mid && nums[mid] == nums[mid-1]) check = mid-1;
                //mid is now the first occurence of the current pair
                
                if(check % 2){    //odd
                    end = mid-1;
                } else{
                    st = mid+1;
                }
            }
            else{
                return nums[mid];
            }
        }
        return -1;
    }
};