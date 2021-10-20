class Solution {
public:
    int nthUglyNumber(int n) {
        static vector<int> ugly{0, 1};
        static int m1 = 1, m2 = 1, m3 = 1;
        if (n < ugly.size()) {
            return ugly[n]; 
        }
        int next = 0;
        while(n >= ugly.size()) {
            next = min(ugly[m1] * 2, min(ugly[m2] * 3, ugly[m3] * 5));
            ugly.push_back(next);
            if (ugly[m1] * 2 == next) {
                ++m1;
            }
            if (ugly[m2] * 3 == next) {
                ++m2;
            }
            if (ugly[m3] * 5 == next) {
                ++m3;
            }
        }
        return ugly[n];
    }
};