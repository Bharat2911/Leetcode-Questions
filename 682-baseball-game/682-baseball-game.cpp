class Solution {
public:
    int calPoints(vector<string>& ops) {
        
        //we will be doing this using the stack;
        
        stack<int>st;
        int sum=0;
        
        for(int i=0;i<ops.size();i++)
        {
            /*
                ops[i]=+
                ops[i]=c
                ops[i]=d
            */
            if(ops[i]=="+")
            {
                int top1=st.top();
                st.pop();
                int top2=st.top();
                st.pop();
                
                int var=top1+top2;
                
                st.push(top2);
                
                st.push(top1);
               
                st.push(var);
            }
            else if(ops[i]=="C")
            {
                st.pop();
            }
            else if(ops[i]=="D")
            {
                int top=st.top();
                st.pop();
                
                st.push(top);
                
                st.push(2*top);
            }
            else
            {
                //if we find the digit
                int x=stoi(ops[i]);
                st.push(x);
            }
        }
        while(!st.empty())
        {
            int top=st.top();
            st.pop();
            
            sum+=top;
        }
        return sum;
    }
};