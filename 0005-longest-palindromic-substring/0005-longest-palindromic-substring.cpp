class Solution {
public:
    string longestPalindrome(string s) {
        
        //two cases will be there either a plaindrome will be of even length or of odd length
        int n=s.length();
        
        int start=0;
        int end=1;
        
        for(int i=0;i<n;i++)
        {
            //odd length
            int low=i-1;
            int high=i+1;
            
            while(low>=0 and high<n and s[low]==s[high])
            {
                if(high-low+1>end)
                {
                    end=high-low+1;
                    start=low;
                }
                
                //xpand kar rha hoga me apne searching spce ko
                
                low--;
                high++;
            }
            
            //even case
            
            low=i-1;
            high=i;
            
            while(low>=0 and high<n and s[low]==s[high])
            {
                if(high-low+1>end)
                {
                    end=high-low+1;
                    start=low;
                }
                low--;
                high++;
                
            }
        }
        return s.substr(start,end);
    }
};