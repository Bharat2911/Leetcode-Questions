class Solution {
public:
    int minCost(string str, vector<int>& time) {
        
        int n=str.length();
        
        int previous=0;
        
        int ans=0;
        
        for(int current=1;current<n;current++)
        {
            if(str[previous]==str[current])
            {
                ans+=min(time[previous],time[current]);
                
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