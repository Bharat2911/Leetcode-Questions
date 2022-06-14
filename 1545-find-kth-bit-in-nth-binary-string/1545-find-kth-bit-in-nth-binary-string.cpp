class Solution {
public:
    string reverse_str(string &str)
    {
        //first invert the given string then 
        //reverse the string 
        
        for(int i=0;i<str.length();i++)
        {
            if(str[i]=='1')
            {
                str[i]='0';
            }
            else
            {
                str[i]='1';
            }
        }
        reverse(str.begin(),str.end());
        return str;
    }
    string make_str(int n)
    {
        //we will be using the recursion to make the prev strings
        
        //base condition 
        if(n==1)
        {
            return "0";
        }
        
        string prev=make_str(n-1);//since n is from 1 so it cant be negative when we subtract
        
        string ans="";
        
        ans=prev+"1"+reverse_str(prev);
        
        return ans;
        
    }
    char findKthBit(int n, int k) {
        
        string ans=make_str(n);
        
        return ans[k-1];
    }
};