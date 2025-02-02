class MyStack {
public:
queue <int> stck;
    MyStack() {
    }
    
    void push(int x) {
        queue <int> temp;
        temp.push(x);
        while (stck.empty() != true)
        {
            int t = stck.front();
            temp.push(t);
            stck.pop();
        }
        stck = temp;
    }
    
    int pop() {
        int t = stck.front();
        stck.pop();
        return t;
    }
    
    int top() {
        return stck.front();
    }
    
    bool empty() {
        return stck.size() == 0;
    }
};
