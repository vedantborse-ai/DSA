class MyQueue {
queue<int> q1;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        q1.push(x);
    }
    
    int pop() {
        int x = q1.front();
        q1.pop();
        return x;
    }
    
    int peek() {
        int x=q1.front();
        return x;
    }
    
    bool empty() {
        return q1.empty();
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