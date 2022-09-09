class Solution {
public:
    string longestPalindrome(string s) {
        
        int n=s.length();
        
        int start=0;
        
        int maxi=1;
        
        for(int i=0;i<n;i++)
        {
            
            //odd case
            int low=i-1;
            int high=i+1;
            
            while(low>=0 and high<n and s[low]==s[high])
            {
                if(high-low+1>maxi)
                {
                    start=low;
                    maxi=high-low+1;
                }
                
                //expand kar rha hu 
                low-=1;
                high+=1;
                
            }
            
            //even case
            low=i;
            high=i+1;
            
            while(low>=0 and high<n and s[low]==s[high])
            {
                if(high-low+1>maxi)
                {
                    start=low;
                    maxi=high-low+1;
                }
                
                //expand kar rha hu 
                low-=1;
                high+=1;
                
            }
        }
        return s.substr(start,maxi);
    }
};