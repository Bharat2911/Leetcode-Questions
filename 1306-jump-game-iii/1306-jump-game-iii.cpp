class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        
        int n=arr.size();
        
        queue<int>q;
        
        vector<int>vis(n,0);
        
        q.push(start);
        
        vis[start]=1;
        
        while(!q.empty())
        {
            int idx=q.front();
            q.pop();
            
            if(arr[idx]==0)
            {
                return true;
            }
            
            if(idx-arr[idx]>=0 and idx-arr[idx]<n and !vis[idx-arr[idx]])
            {
                vis[idx-arr[idx]]=1;
                
                q.push(idx-arr[idx]);
            }
            
            if(idx+arr[idx]>=0 and idx+arr[idx]<n and !vis[idx+arr[idx]])
            {
                vis[idx+arr[idx]]=1;
                
                q.push(idx+arr[idx]);
            }
        }
        return false;
    }
};