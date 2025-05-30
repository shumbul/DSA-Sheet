class MyStack {
     queue<int> q1, q2;
public:
    MyStack() {
       
    }
    
    void push(int x) {
        q1.push(x);
    }
    
    int pop() {
        while (q1.size()!=1)
        {
            cout<<"Fr "<<q1.front()<<endl;
            q2.push(q1.front());
            q1.pop();
        }
        int x=q1.front();
        cout<<x<<endl;
        q1.pop();
        swap(q1, q2);
        return x;
    }
    
    int top() {
        while (q1.size()!=1)
        {
            q2.push(q1.front());
            q1.pop();
        }
        int x=q1.front();
        swap(q1, q2);
        q1.push(x);
        q2.pop();
        return x;
    }
    
    bool empty() {
        if (q1.empty())
            return true;
        return false;
    }
};
