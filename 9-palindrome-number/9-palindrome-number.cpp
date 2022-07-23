class Solution {
public:
    bool ispal(string&s,int low,int high)
    {
        while(low<=high)
        {
            if(s[low++]!=s[high--]){
                return false;
            }
        }
        return true;
    }
    bool isPalindrome(int x) {
        
        string str=to_string(x);
        
        return (ispal(str,0,str.length()-1));
    }
};