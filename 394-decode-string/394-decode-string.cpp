class Solution {
public:
    //makign the recursive function
    string solve(string &s,int &i)
    {
        int n=s.length();
        string ans;
        
        while(i<n and s[i]!=']')
        {
            if(isdigit(s[i]))
            {    
                int k=0;
                while(i<n and isdigit(s[i]))
                    k=k*10+(s[i++]-'0');
                i++;
                
                //recursive call bracket ke andar se answer nikal ke dega
                string temp=solve(s,i);
                
                
                
                while(k-- > 0)
                    ans+=temp;//append k times
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
        
        //usign the recursion here
        int i=0;
        return solve(s,i);
    }
};