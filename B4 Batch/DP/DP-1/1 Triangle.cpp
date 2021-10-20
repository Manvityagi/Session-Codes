class Solution
{
public:
    int minimumTotal(vector<vector<int> > &triangle)
    {
        int r = triangle.size();
        vector<vector<int> > dp;
        dp = triangle;

        for (int i = r - 2; i >= 0; i--)
        {
            int c = triangle[i].size();

            for (int j = 0; j < c; j++)
            {
                int op1 = dp[i + 1][j + 1];
                int op2 = dp[i + 1][j];
                dp[i][j] += min(op1, op2);
            }
        }

        return dp[0][0];
    }
};