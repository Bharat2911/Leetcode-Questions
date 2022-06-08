class Solution {
public:
    bool ispal(string s)
    {
        int n=s.length();
        int low=0;
        int high=n-1;
        
        while(low<high)
        {
            if(s[low++]!=s[high--])
            {
                return false;
            }
        }
        return true;
    }
    int removePalindromeSub(string s) {
        
        //answer can only be one or two 
        //so if the string is palindrome then the answer is one else answer is two
        if(ispal(s))return 1;
        return 2;
    }
};