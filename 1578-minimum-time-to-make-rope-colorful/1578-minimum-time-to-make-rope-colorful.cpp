class Solution {
public:
    int minCost(string colors, vector<int>& time) {
        
        //if we have two consecutive then i have toremove one and we will remove whose time is max
        
        //we will not sort it otherwise my position get changed
        // sort(colors.begin(),colors.end());
        
        int n=colors.size();
        
        int previous=0;
        
        int ans=0;
        
        for(int current=1;current<n;current++)
        {
            if(colors[previous]==colors[current])
            {
               ans+=min(time[previous],time[current]);
                
                //and we have to remove so we will remove the one with min time
                
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