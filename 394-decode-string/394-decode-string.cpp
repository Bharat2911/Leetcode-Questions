class Solution {
public:
    string solve(string&s,int &i)
    {
        string ans;
        
         while(i<s.length() and s[i]!=']')
         {
             if(s[i]>='0' and s[i]<='9')//means there is a digit
             {
                 int k=0;
                 while(i<s.length() and isdigit(s[i]))
                     k=k*10+s[i++]-'0';
                 i++;
                 
                 ///recursive call 
                 string temp=solve(s,i);
                 
                 //apppend k times that we get from the recursive function
                 while(k-- > 0)
                     ans+=temp;
                 i++;
               
                 
                 
             }
             else
             {
                 ans+=s[i];
                 i++;
                 
             }
         }
        return ans;
    }
    string decodeString(string s) {
        
        int n=s.length();
        int i=0;
        
        return solve(s,i);
    }
};