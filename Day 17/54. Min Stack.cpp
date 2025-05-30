class MinStack {
    stack<int> s1, s2;
public:
    MinStack() {
       
    }
    
    void push(int val) {
        s1.push(val);
        if (s2.empty() || val<=s2.top()) //keeps s2 in sync with the current min at each point
            s2.push(val);
    }
    
    void pop() {
        if (s1.top()==s2.top()) //check if we are removing the current min
            s2.pop();
        s1.pop();
    }
    
    int top() {
       return s1.top();
    }
    
    int getMin() {
        return s2.top();
    }
};
