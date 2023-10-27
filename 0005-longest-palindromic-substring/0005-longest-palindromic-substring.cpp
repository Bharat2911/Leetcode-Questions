class Solution {
public:
    string longestPalindrome(string s) {
        
        int n=s.length();
        
        //i will be using the even odd length man
        
        int start=0;
        
        int end=1;
        
        
        //odd case mai current se left aur right ko match karna chaiye
        
        for(int i=0;i<n;i++)
        {
            // odd case we will be doing here 
            
            int low=i-1;
            int high=i+1;
            
            while(low>=0 and high<n and s[low]==s[high])
            {
                if(end<high-low+1)
                {
                    start=low;
                    end=high-low+1;
                }
                
                low--;
                high++;
                
            }
            
            //even case
             low=i;
             high=i+1;
            
            while(low>=0 and high<n and s[low]==s[high])
            {
                if(end<high-low+1)
                {
                    start=low;
                    end=high-low+1;
                }
                
                low--;
                
                high++;
            }
        }
        return s.substr(start,end);
    }
};