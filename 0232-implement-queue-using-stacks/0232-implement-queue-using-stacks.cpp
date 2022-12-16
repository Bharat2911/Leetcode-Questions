class MyQueue {
public:
    MyQueue() {
        
    }
    stack<int>s1;
    stack<int>s2;
    
    void push(int x) {
        
        while(!s1.empty())
        {
            int top=s1.top();
            s1.pop();
            
            s2.push(top);
        }
        s1.push(x);
        
        while(!s2.empty())
        {
            int top=s2.top();
            s2.pop();
            s1.push(top);
        }
    }
    
    int pop() {
        
        if(s1.empty())return -1;
        
        else
        {
            int x=s1.top();
            s1.pop();
            
            return x;
        }
    }
    
    int peek() {
        
        if(s1.empty())return -1;
        
        return s1.top();
    }
    
    bool empty() {
        
        return s1.empty();
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