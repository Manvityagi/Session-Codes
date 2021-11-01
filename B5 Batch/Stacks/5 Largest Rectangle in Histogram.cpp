class Solution {
public:
    vector<int> nextSmallerElement(vector<int> &arr){
        stack<int> st;
        int n = arr.size();
        vector<int> ans(n,n);
        for(int i = 0; i < n; i++){
            while(!st.empty() && arr[i] < arr[st.top()]){
                ans[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }
    
    vector<int> previousSmallerElement(vector<int> &arr){
        stack<int> st;
        int n = arr.size();
        vector<int> ans(n,-1);
        for(int i = n-1; i >= 0; i--){
            while(!st.empty() && arr[i] < arr[st.top()]){
                ans[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }
    
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st; //store indices
        vector<int> left, right;
        right = nextSmallerElement(heights);
        left = previousSmallerElement(heights);
        
        int ans = 0;
        for(int i = 0; i < n; i++){
            ans = max(ans,heights[i]*(right[i] - left[i] - 1));
        }
        
        return ans;
    }
};