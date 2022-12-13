class Solution {
public:
    bool isPalindrome(string s) {
        
        string res="";
        
        for(auto itr:s)
        {
            
             if(itr>='A' and itr<='Z')
            {
                res+=tolower(itr);
            }
            else if(itr>='a' and itr<='z')
            {
                res+=itr;
            }
            else if(itr>='0' and itr<='9')
            {
                res+=itr-'0';
            }
            else
            {
                continue;
            }
        }
        string str=res;
        reverse(str.begin(),str.end());
        
        if(res==str)
        {
            return true;
            
        }
        return false;
        
    }
};