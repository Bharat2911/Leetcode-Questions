class Solution {
public:
    int calculate(string s) {
        
        int n=s.length();
        
        stack<int>st;
        
        int res=0;
        int curr=0;
        int sign=1;
        
      for(int i=0;i<n;i++)
      {
          if(s[i]>='0' and s[i]<='9')//this means that i am getting the digit
          {
              curr=s[i]-'0';
              
              while(i+1<n and (s[i+1]>='0' and s[i+1]<='9'))
              {
                  curr=curr*10+(s[i+1]-'0');
                  
                  i++;
              }
              curr=curr*sign;
              res+=curr;
              //reset the values
              curr=0;
              sign=1;
          }
          
          else if(s[i]=='+')
          {
              sign=1;
          }
          else if(s[i]=='-')
          {
              sign=-1;
          }
          else if(s[i]=='(')
          {
              st.push(res);
              st.push(sign);
              
              //reset the values
              
              res=0;
              sign=1;
              
          }
          else if(s[i]==')')
          {
              //when we get the close bracket pop out
              int prev_sign=st.top();
              st.pop();
              
              int num=st.top();
              st.pop();
              
              res=res*prev_sign;
              res+=num;
          }
          
      }
        return res;
    }
};