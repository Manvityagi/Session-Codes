class MinStack {
    int mn = INT_MAX;
    stack<pair<int,int>> st;
    
public:
    /** initialize your data structure here. */
    MinStack() {        
    }
    
    void push(int x) {
        int tmp = st.empty() ? mn : st.top().second;
        int mn = min(x,tmp);
        st.push(make_pair(x,mn));   
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().first; 
    }
    
    int getMin() {
        return st.top().second;
    }
};