class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> arr1(26,0); 
        vector<int> arr2(26,0); 
        
        for(auto c : s){
            arr1[c-'a']++;
        }
        
        for(auto c : t){
            arr2[c-'a']++;
        }
        
        for(int i = 0; i < 26; i++){
            if(arr1[i] != arr2[i]) return false;
        }
        return 1;
    }
};