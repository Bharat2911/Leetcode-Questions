class Solution {
public:
    int minCost(string str, vector<int>& time) {
        
        int n=str.length();
        
        int ans=0;
        
        int previous=0;
        
        for(int current=1;current<n;current++)
        {
            if(str[previous]==str[current])
            {
                ans+=min(time[previous],time[current]);
                
                //i have to remove
                
                if(time[previous]<time[current])
                {
                    previous=current;
                }
            }
            else
            {
                previous=current;
            }
        }
        return ans;
    }
};