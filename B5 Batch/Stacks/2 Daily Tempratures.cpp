class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &arr)
    {
        stack<int> st;
        int n = arr.size();
        vector<int> ans(n, 0);
        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && arr[i] > arr[st.top()])
            {
                ans[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }

    vector<int> dailyTemperatures(vector<int> &arr)
    {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        vector<int> NGE = nextGreaterElement(arr);
        for (int i = 0; i < arr.size(); i++)
        {
            if (NGE[i])
                NGE[i] -= i;
        }
        return NGE;
    }
};