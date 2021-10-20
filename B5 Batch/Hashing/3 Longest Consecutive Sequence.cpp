/*
    look at the entering of the logic: if(!num_set.contains(num-1)).
    That means, for example, 6,5,4,3,2,1 input, only the value 1 is valid for the loop(all other values have its value - 1 in the set), that is O(n).
    Another corner example, 2, 5, 6, 7, 9, 11. All of these numbers are the "entrance" for the logic but the while loop doesn't run much. That is O(n) as well.
*/
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        for(auto num : nums) st.insert(num);
        
        int longest_len = 0;
        
        for(auto num : st){
            if(st.find(num-1) == st.end()){
                int curr_num = num;
                int curr_len = 1;
                
                while(st.find(curr_num + 1) != st.end()){
                    curr_num++;
                    curr_len++;
                }
                longest_len = max(longest_len,curr_len);
            }
        }
        
        return longest_len;
    }
};