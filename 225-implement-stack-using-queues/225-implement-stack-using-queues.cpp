class MyStack {
public:
    MyStack() {
        
    }
    queue<int>q1;
    queue<int>q2;
    
    
    void push(int x) {
        
        while(!q1.empty())
        {
            int a=q1.front();
            q1.pop();
            
            q2.push(a);
            
            
        }
        q1.push(x);
        
        while(!q2.empty())
        {
            int a=q2.front();
            q2.pop();
            
            q1.push(a);
        }
    }
    
    int pop() {
        
        if(q1.empty())
        {
            return -1;
        }
        int a=q1.front();
        q1.pop();
        return a;
    }
    
    int top() {
        
        return q1.front();
    }
    
    bool empty() {
        
        return q1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */