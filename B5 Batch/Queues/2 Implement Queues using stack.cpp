class MyQueue {
public:
    stack<int> push_stack, pop_stack;
    
    MyQueue() {
    
    }
    
    void push(int x) {
        push_stack.push(x);
    }
    
    int pop() {
        if(!pop_stack.empty()) {
            int ans = pop_stack.top();
            pop_stack.pop();
            return ans;
        }
        while(!push_stack.empty()){
            pop_stack.push(push_stack.top());
            push_stack.pop();
        }
        int ans = pop_stack.top();
        pop_stack.pop();
        return ans;
    }
    
    int peek() {
        if(!pop_stack.empty()) {
            return pop_stack.top();
        }
        while(!push_stack.empty()){
            pop_stack.push(push_stack.top());
            push_stack.pop();
        }
        return pop_stack.top();
    }
    
    bool empty() {
        return (push_stack.empty() && pop_stack.empty());
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */