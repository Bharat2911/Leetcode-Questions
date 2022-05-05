class MyStack
{
    public:
        queue<int> q1;
    queue<int> q2;

    MyStack() {}

    void push(int x)
    {
       	//q1->q2;
       	//x->q1
       	//q2->q1;

        while (!q1.empty())
        {
            int top = q1.front();
            q1.pop();
            q2.push(top);
        }
        q1.push(x);

        while (!q2.empty())
        {
            int top = q2.front();
            q2.pop();
            q1.push(top);
        }
    }

    int pop()
    {
        int x = 0;

        if (!q1.empty())
        {
            x = q1.front();
            q1.pop();
        }
        return x;
    }

    int top()
    {

        return q1.front();
    }

    bool empty()
    {
        if (q1.empty()) return true;
        else return false;
    }
};

/**
 *Your MyStack object will be instantiated and called as such:
 *MyStack* obj = new MyStack();
 *obj->push(x);
 *int param_2 = obj->pop();
 *int param_3 = obj->top();
 *bool param_4 = obj->empty();
 */