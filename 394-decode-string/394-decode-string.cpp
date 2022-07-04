class Solution {
public:
    string decodeString(string s) {
        
        //asked in amazon
        
        //will be doing this using thetwo stack
        int n=s.length();
        
        stack<string>char_st;
        stack<int>num_st;
        
        int num=0;
        string res="";
        
        for(auto itr:s)
        {
            //we have to tackel the four cases here
            //digit ,char ,open bracket,close bracket
            
            if(isdigit(itr))
            {
                //make the number 
                num=num*10+(itr-'0');
            }
            
            else if(isalpha(itr))
            {
                res+=itr;
                
            }
            else if(itr=='[')
            {
                //here we have to push in the stack
                char_st.push(res);
                num_st.push(num);
                
                //and reset the value again
                num=0;
                res="";
            }
            else 
            {
                //main step
                //when we have closing value 
                string temp=res;
                res=char_st.top();
                char_st.pop();
                int freq=num_st.top();
                num_st.pop();
                
                while(freq>0)
                {
                    res+=temp;
                    freq--;
                }
                num=0;
                //reset the digit
                
                
            }
        }
        //take away points
        //open bracket push in stack
        //close bracket pop from stack
        return res;
    }
};