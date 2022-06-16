class Solution {
public:
    string longestPalindrome(string s) {
         int n=s.length();
        int start=0;
        int end=1;
        
        for(int i=1;i<n;i++)
        {
            //odd case
            int low=i-1;
            int high=i;
            while(low>=0 && high<n && s[low]==s[high])
            {
                if(high-low+1>end)
                {
                    start=low;
                    end=high-low+1;
                    
                }
                low--;
                high++;
            }
            //even case
               low=i-1;
               high=i+1;
            
            while(low>=0 && high<n && s[low]==s[high])
            {
                if(high-low+1>end)
                {
                    start=low;
                    end=high-low+1;
                }
                low--;
                high++;
            }
        }
        string str="";
        for(int i=start;i<=end+start-1;i++)
        {
            str.push_back(s[i]);
        }
        return str;
    }
};