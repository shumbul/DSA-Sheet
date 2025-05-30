class MyQueue {
    stack<int> s1, s2;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        if (s1.empty() && s2.empty())
        {
            s2.push(x);
            return;
        }
        while (!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
        s1.push(x);
        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
    }
    
    int pop() {
        int x=s2.top();
        s2.pop();
        return x;
    }
    
    int peek() {
        int x=s2.top();
        return x;
    }
    
    bool empty() {
        if (s2.empty())
            return true;
        return false;
    }
};
/*
s1=3 4 5 6 
s2= 6 5 4 3
pop- s2 ka top
push- s2 to s1, s1 me push, s1 to s2
peek- s2 ka top
 */
