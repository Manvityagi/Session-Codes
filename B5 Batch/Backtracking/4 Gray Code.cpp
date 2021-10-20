//Approach 1
class Solution {
  public:

    vector < string > helper(int n) {
      if (n == 1) {
        vector < string > ans = {
          "0",
          "1"
        };
        return ans;
      }

      vector < string > prev = helper(n - 1);

      vector < string > rev(prev);
      reverse(rev.begin(), rev.end());
      vector < string > ans;

      for (auto s: prev) {
        ans.emplace_back("0" + s);
      }
      for (auto s: rev) {
        ans.emplace_back("1" + s);
      }
      return ans;
    }

  int to_dec(string s) {
    int ans = 0;
    for (int i = s.size() - 1, mul = 1; i >= 0; mul *= 2, i--) {
      ans += ((s[i] - '0') * mul);
    }
    return ans;
  }

  vector < int > grayCode(int n) {
      if(n == 0) return {0};
    vector < string > ans = helper(n);
    vector < int > dec;

    for (auto s: ans) {
      int cur = to_dec(s);
      dec.emplace_back(cur);
    }
    return dec;

  }
};

//Approach 2
class Solution {
public:
    vector<int> grayCode(int n) {
        if(n == 1){
            return {0,1};
        }
        
        vector<int> prev = grayCode(n-1);
        int total = prev.size();
        int curr_add = 1<<(n-1);
        for(int i = total-1; i >= 0; i--){
            prev.push_back(curr_add + prev[i]);
        }
        
        return prev;
    }
};