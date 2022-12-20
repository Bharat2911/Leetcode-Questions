class Solution {
public:
    bool safe(vector<int>&piles,int speed,int h)
    {
         int total=0;
        for (int i=0; i<piles.size(); i++){
            total+= (piles[i]/speed)+(piles[i]%speed!=0);
            if (total>h)return false;
        }
        return (total<=h);
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        
        //this is same as allocate min number of pages
        // ..will apply binray search so for that we need range
        
        int low=1;
        int high=piles[0];
        
        for(auto itr:piles)
        {
            high=max(high,itr);
        }
        
        int ans=high;
        
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            
            if(safe(piles,mid,h))
            {
                ans=mid;
                //try for minimum answer
                high=mid-1;
            }
            else
            {
                //usme possible nahi to usse kam me bhi possible nahi try for max answer
                low=mid+1;
                
            }
        }
        return ans;
    }
};