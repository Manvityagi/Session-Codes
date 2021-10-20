//APP - 1
class Solution {
public:
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        unordered_map<int,unordered_set<int>> mp;
        for(int i = 0; i < n; i++){
            unordered_set<int> st;
            mp[stones[i]] = st;
        }
        int dest = stones[n-1];
        
        mp[stones[0]].insert(1);
        
        for(int i = 0; i < stones.size(); i++){
            int currStone = stones[i];
            unordered_set<int> jumps = mp[currStone];
            
            for(int jump : jumps){
                int reachedPosition = currStone + jump;
                if(reachedPosition == dest) return 1;
                
                if(mp.find(reachedPosition) != mp.end()){
                    if(jump > 1)
                    mp[reachedPosition].insert(jump-1);
                    mp[reachedPosition].insert(jump);
                    mp[reachedPosition].insert(jump+1);
                }
            }
        }
        return 0;
    }
};

//APP - 2
/*

The maximum jump size the frog can make at each stone if possible is something like: 
stone:      0, 1, 2, 3, 4, 5
jump size:  1, 2, 3, 4, 5, 6 

(suppose jump of size k + 1 at each stone as that will give us the maximum jump difference/distance)

That's why max jump size is order of n and not 2^32 and hence dp dimensions of order of n are enough.

dp[i][j] = at stone i, the frog can or cannot make jump of size j

*/

class Solution {
public:
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        vector<vector<bool>> dp(n,vector<bool>(n+1,0));
        
        dp[0][1] = true;
        for(int i = 1; i < n; i++){
            for(int j = 0; j < i; j++){
                int jump_length = stones[i] - stones[j];
                if(jump_length < 0 || jump_length > n || !dp[j][jump_length]) continue;
                if(jump_length - 1 >= 0) dp[i][jump_length - 1] = true;
                dp[i][jump_length] = true;
                if(jump_length + 1 <= n) dp[i][jump_length + 1] = true;
                if(i == n - 1) return true;
            }
        }

        return false;
    }
};