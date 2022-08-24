class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        
        //using the sliding window here
        
        int n=blocks.length();
        
        int i=0;
        int j=0;
        
        int ans=INT_MAX;
        
        int count=0;
        
        while(j<n)
        {
           if(blocks[j]=='W')
           {
               count++;
           }
            
            if(j-i+1<k)//window not hit
            {
                j++;
            }
            //window hit ho gyi
            //ans 
            //shirnk
            else if(j-i+1==k)
            {
              ans=min(ans,count);
                
                if(blocks[i]=='W')
                {
                    count--;
                }
                //slide the window
                i++;
                j++;
            }
        }
        return ans;
    }
};