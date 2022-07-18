class Solution {
public:
  bool ispal(string s,int i,int j)
    {
        while(i<=j)
        {
            if(s[i++]!=s[j--])
            {
                return false;
            }
        }
        return true;
        
    }
    bool valid_char(char c)
    {
        if((c>='A' and c<='Z') || (c>='a' and c<='z') || (c>='0' and c<='9'))
        {
            return true;
        }
        return false;
    }
   char to_lower(char c)
   {
       if((c>='a' and c<='z') || (c>='0' and c<='9'))
       {
           return c;
       }
       char temp;
       temp=c-'A'+'a';
       return temp;
   }
    bool isPalindrome(string s) {
        
        //remove non-alphanumeric character
        //convert to lower case
        //check palindrome
        string temp="";
        int n=s.length();
        for(int i=0;i<n;i++)
        {
            if(valid_char(s[i]))
            {
                temp.push_back(s[i]);
            }
        }
        for(int i=0;i<temp.length();i++)
        {
            temp[i]=to_lower(temp[i]);
        }
        int l=temp.size();
        
       return ispal(temp,0,l-1);
        
    }
};