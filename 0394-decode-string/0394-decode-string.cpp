class Solution {
public:
    string decodeString(string s) {
        
        //we will be using the stack here 
        //basically two stacks one for digit and other for string
        
        //[ ->push in the stack
        //] ->pop from the stack
        
        int n=s.length();
        
        stack<int>st1;
        stack<string>st2;
        
        int num=0;
        
        string res="";
        
        for(auto itr:s)
        {
            if(isdigit(itr))
            {
                num=num*10+(itr-'0');
            }
            
            else if(isalpha(itr))
            {
                res+=itr;
            }
            
            else if(itr=='[')
            {
                //push in the stack
                st1.push(num);
                
                st2.push(res);
                
                num=0;
                res="";
            }
            else if(itr==']')
            {
                //pop from the stack
                
                string temp=res;
                
                res=st2.top();
                st2.pop();
                
                int freq=st1.top();
                st1.pop();
                
                
                while(freq>0)
                {
                    res+=temp;
                    
                    freq--;
                }
                num=0;
            }
        }
        return res;
    }
};