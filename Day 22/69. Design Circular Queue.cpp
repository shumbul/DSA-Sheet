class MyCircularQueue {
     vector<int> q;
     int K;
        int front=-1;
        int rear=-1;
        int count=0; //no. of elements in queue
public:
    MyCircularQueue(int k) {
       q.resize(k);
       K=k;
    }
    
    bool enQueue(int value) {
        if (isFull())
            return false;
        if (front==-1 && rear==-1) //first element
            front=0;
        rear=(rear+1)%K; //circular logic
            q[rear]=value;
            count++;
            return true;
    }
    
    bool deQueue() {
        if (isEmpty())
            return false;
        if (count==1)
        {
            front=-1; //reset
            rear=-1; //reset
            count--;
        }
        else
        {
            front=(front+1)%K; //circular logic
            count--;
        }
        return true;
    }
    
    int Front() {
        if (isEmpty())
            return -1;
        return q[front];
    }
    
    int Rear() {
        if (isEmpty())
            return -1;
        return q[rear];
    }
    
    bool isEmpty() {
        if (count==0)
            return true;
        else
            return false;
    }
    
    bool isFull() {
        if (count==q.size())
            return true;
        else
            return false;
    }
};
