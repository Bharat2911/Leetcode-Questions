class Solution {
public:
    bool safe(vector<int>&arr,int mid,int m)
    {
        int group=0;
        int sum=0;
        
        for(int i=0;i<arr.size();i++)
        {
            if(sum+arr[i]>mid)
            {
                group++;
                sum=arr[i];
                
                if(sum>mid)
                {
                    return false;
                }
                
            }
            else
            {
                sum+=arr[i];
            }
        }
        if(group<m)return true;
        
        return false;
    }
    int shipWithinDays(vector<int>& arr, int m) {
        
        int low=arr[0];
        
        int high=arr[0];
        
        for(int i=0;i<arr.size();i++)
        {
            low=min(low,arr[i]);
            
            high+=arr[i];
        }
        
        int ans=0;
        
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            
            if(safe(arr,mid,m))
            {
                ans=mid;
                
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        
        }
            return ans;
    }
};