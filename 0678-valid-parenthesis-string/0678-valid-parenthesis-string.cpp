class Solution {
public:
    //T.C=O(n)
    //S.C=O(1)
    
    bool checkValidString(string s) {
        
        int bal=0;
        
        for(int i=0;i<s.length();i++)
        {
            if(s[i]==')')
            {
                bal--;
            }
            else
            {
                bal++;
                
            }
            if(bal<0)
            {
                return false;
            }
        }
        bal=0;
        
        for(int i=s.length()-1;i>=0;i--)
        {
            if(s[i]=='(')
            {
                bal--;
            }
            else
            {
                bal++;
            }
            if(bal<0)
            {
                return false;
            }
        }
        return true;
    }
};