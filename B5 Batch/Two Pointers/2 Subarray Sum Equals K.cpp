class Solution {
public:
    int subarraySum(vector<int>& arr, int sum) {
        int n = arr.size();
    	map<int,int> mp; 
    	int pref = 0,ans = 0; 
    	mp[0] = 1;
    	for(int i = 0; i < n; i++){
    	    pref += arr[i]; 
    	    if(mp.find(pref-sum) != mp.end()){
    	        ans+=mp[pref-sum]; 
    	    }
             mp[pref]++; 
    	}
    	return ans;
    }
};