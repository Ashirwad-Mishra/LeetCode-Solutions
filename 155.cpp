class MinStack {
public:
stack <int> s , mS;
    MinStack() {
        
    }
    
    void push(int val) {
        s.push(val);
        if (mS.empty() || val <= mS.top()) mS.push(val);
    }
    
    void pop() {
        if (s.top() == mS.top()) mS.pop();
        s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return mS.top();
    }
};
