//Maximal Rectangle
#define F first
#define S second 
class Solution
{
public:
    int maximalRectangle(vector<vector<char> > &matrix)
    {
        int r = matrix.size();
        if (!r)
            return 0;
        int c = matrix[0].size();

        vector<vector<int> > heights(r, vector<int>(c));
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                heights[i][j] = matrix[i][j] - '0';
                if (i && heights[i][j])
                    heights[i][j] += heights[i - 1][j];
            }
        }
        vector<vector<int> > leftMin(r, vector<int>(c, 0));
        vector<vector<int> > rightMin(r, vector<int>(c, 0));
        stack<int> st;
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (st.empty())
                {
                    leftMin[i][j] = -1;
                }
                else
                {
                    //pop out until stack top height is greater than current height
                    while (!st.empty() && heights[i][st.top()] >= heights[i][j])
                        st.pop();
                    leftMin[i][j] = st.empty() ? -1 : st.top();
                }
                st.push(j);
            }

            while (!st.empty())
                st.pop();

            for (int j = c - 1; j >= 0; j--)
            {
                if (st.empty())
                {
                    rightMin[i][j] = c;
                }
                else
                {
                    while (!st.empty() && heights[i][st.top()] >= heights[i][j])
                        st.pop();
                    rightMin[i][j] = st.empty() ? c : st.top();
                }
                st.push(j);
            }
            
              while (!st.empty())
                st.pop();
        }
        
        int ans = 0;
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                ans = max(ans, heights[i][j] * (rightMin[i][j] - leftMin[i][j] - 1));
            }
        }

        return ans;
    }
};




/* Largest Rectangle in Histogram */

class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        int n = heights.size();
        stack<int> st; //store indices
        vector<int> left(n), right(n);

        //stack will always have an increasing order
        for (int i = 0; i < n; i++)
        {
            if (st.empty())
            {
                left[i] = -1;
            }
            else
            {
                //pop out until stack top height is greater than current height
                while (!st.empty() && heights[st.top()] >= heights[i])
                    st.pop();
                left[i] = st.empty() ? -1 : st.top();
            }
            st.push(i);
        }

        while (!st.empty())
            st.pop();

        for (int i = n - 1; i >= 0; i--)
        {
            if (st.empty())
            {
                right[i] = n;
            }
            else
            {
                while (!st.empty() && heights[st.top()] >= heights[i])
                    st.pop();
                right[i] = st.empty() ? n : st.top();
            }
            st.push(i);
        }

        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans = max(ans, heights[i] * (right[i] - left[i] - 1));
        }

        return ans;
    }
};
