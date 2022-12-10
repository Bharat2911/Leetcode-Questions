class Solution {
public:
    string decodeString(string s) {
        
        //we only have top check for four things
        int n=s.length();
        string ans="";
        string res;
        
        int num=0;
        
        stack<int>s1;
        stack<string>s2;
        
        for(int i=0;i<s.length();i++)
        {
            if(s[i]>='0' and s[i]<='9')
            {
                
                num=num*10+s[i]-'0';
                
                
            }
            else if(isalpha(s[i]))
            {
                res+=s[i];
            }
            else if(s[i]=='[')
            {
                //push in the stack 
                s1.push(num);
                s2.push(res);
                
                //reset the values
                res="";
                num=0;
            }
            else
            {
                //pop();
                int freq=s1.top();
                s1.pop();
                
                string temp=res;
                res=s2.top();
                s2.pop();
                
                
                while(freq>0)
                {
                    res+=temp;
                    freq--;
                }
                
                
            }
        }
        return res;
    }
};