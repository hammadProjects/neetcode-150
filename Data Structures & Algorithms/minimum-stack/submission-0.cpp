class MinStack {
public:
    stack<int> minStack;
    stack<int> normalStack;

    MinStack() {

    }
    
    void push(int val) {
        normalStack.push(val);
        val = min(val, minStack.empty() ? val : minStack.top());
        minStack.push(val);
    }
    
    void pop() {
        normalStack.pop();
        minStack.pop();
    }
    
    int top() {
        return normalStack.top();
    }
    
    int getMin() {
        return minStack.top();
    }
};
