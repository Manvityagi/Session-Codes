class Solution {
public:
    
    bool isPossible(vector<int>& weights, int ship_capacity, int days){
        int n = weights.size(); 
        int i = 0;
        
        int used_days = 1, curr_wt = 0;
        for(int i = 0; i < n; i++){
            //edge case 
            if(weights[i] > ship_capacity) return 0;

            curr_wt += weights[i];
            if(curr_wt > ship_capacity){
                used_days++;
                curr_wt = weights[i];
            } 
            if(used_days > days) return 0;
        }
        return 1;
        
    }
    
    int shipWithinDays(vector<int>& weights, int days) {
        //return minimum weight capacity 
        
        //worst case - each weight(5*10^4) is of 500kgs and days = 1
        //ship capacity = 500*5*10^4 = 25*10^6
        
        int lo = *max_element(weights.begin(),weights.end()), hi = accumulate(weights.begin(),weights.end(),0); //ship capacity range
        int ans = INT_MAX;
        
        while(lo <= hi){
            int mid = (lo+hi)>>1;
            if(isPossible(weights,mid,days)){
                ans = min(ans,mid); //50 kg works, so more than that will obviously work
                hi = mid-1;
            } else {
                lo = mid+1;
            }
        }
        return ans;
    }
};