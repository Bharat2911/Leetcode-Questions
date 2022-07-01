class Solution {
public:
    string largestOddNumber(string num) {
       
        //itrate from last if the curr number is odd then return the substring till that point
        int n=num.length();
        int index=0;
        for( int i=n-1;i>=0;i--)
        {
            int ele=num[i]-'0';
            
            if(ele&1)//if odd
            {
                return num.substr(0,i+1);
                break;
            }
        }
      return "";
    }
};