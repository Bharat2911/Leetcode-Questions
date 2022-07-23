class Solution {
public:
    void merge(int low,int mid,int high,vector<pair<int,int>>&arr,vector<int>&ans)
    {
        vector<pair<int,int>>temp(high-low+1);
        
        int i=low;
        int j=mid+1;
        int k=0;
        
        while(i<=mid and j<=high)
        {
           if(arr[i].first<=arr[j].first)
           {
               temp[k++]=arr[j++];
           }
           else
            {
               ans[arr[i].second]+=high-j+1;
               temp[k++]=arr[i++];
            }
        }
        while(i<=mid)
        {
            temp[k++]=arr[i++];
        }
        while(j<=high)
        {
            temp[k++]=arr[j++];
        }
        for(int i=low;i<=high;i++)
        {
            arr[i]=temp[i-low];
        }
    }
    void mergesort(int low,int high,vector<pair<int,int>>&arr,vector<int>&ans)
    {
        if(low<high)
        {
            int mid=low+(high-low)/2;
            
            mergesort(low,mid,arr,ans);
            mergesort(mid+1,high,arr,ans);
            
            merge(low,mid,high,arr,ans);
        }
    }
    vector<int> countSmaller(vector<int>& nums) {
        
        int n=nums.size();
        int low=0;
        int high=n-1;
        
        vector<int>ans(n,0);
        
        vector<pair<int,int>>arr;
        
        for(int i=0;i<n;i++)
        {
            arr.push_back({nums[i],i});
        }
        
        mergesort(low,high,arr,ans);
        return ans;
    }
};