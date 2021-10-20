/*

T(n) = for i in 1 to n-1 : +2*(T(i) + T(n-i))
i.e.
T(n) = 2*(T(1) + T(n-1) + T(2) + T(n-2) + ... + T(n-1) + T(1)) ,
T(n) = 2 * 2(T(1) + T(2) + ...+ T(n-2) + T(n-1))
T(n) = 4 * (T(1) + T(2) + ...+ T(n-2) ) + 4 * T(n-1)

As T(n-1) = 4 * (T(1) + T(2) + ...+ T(n-2) )
using this in the above equation

T(n) = T(n-1) + 4 * T(n-1)
T(n) = 5 * T(n-1)

If we open this:
T(n) = 5 * 5 * T(n-2) = 5 * 5 * 5 * T(n-3) = 5 * 5 * ... * 5 (n times)
so T(n) = O(5^n)

*/
class Solution {
public:
    map<pair<string,string>,int> mp; 
    bool isScramble(string s1, string s2) {
        if(s1 == s2) {return mp[{s1,s2}] = true;} 
        
        if(mp.find({s1,s2}) != mp.end()) return mp[{s1,s2}];
        
        int freq[26] = {0};
        int n = s1.length(); 
        for(int i=0; i<n; i++){
            freq[s1[i]-'a']++;
            freq[s2[i]-'a']--;
        }
        for(int i = 0; i < 26; i++)
            if(freq[i] != 0) return mp[{s1,s2}] = false;
        
        for(int i=1; i<=n-1; i++){
            if(isScramble(s1.substr(0,i), s2.substr(0,i)) && isScramble(s1.substr(i), s2.substr(i)))
                return mp[{s1,s2}] = true;
            if(isScramble(s1.substr(0,i), s2.substr(n-i)) && isScramble(s1.substr(i), s2.substr(0,n-i)))
                return mp[{s1,s2}] = true;
        }
        return mp[{s1,s2}] = false;
    }
};