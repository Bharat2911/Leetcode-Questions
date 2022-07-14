class Solution {
public:
    string decodeString(string s) {
        
        stack<int>f_st;
        stack<string>ch_st;
        
        int num=0;
        string res="";
        
        
        for(auto itr:s)
        {
            //need to tackel the dour cases
            
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
                f_st.push(num);
                ch_st.push(res);
                
                //reset the values
                
                num=0;
                res="";
                
            }
            else
            {
                string temp=res;
                res=ch_st.top();
                ch_st.pop();
                
                int freq=f_st.top();
                f_st.pop();
                
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