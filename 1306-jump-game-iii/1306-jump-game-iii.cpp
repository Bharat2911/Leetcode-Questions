class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        
        int n=arr.size();
        
        queue<int>q;
        
        vector<int>vis(n,0);
        
        q.push(start);
        
        while(!q.empty())
        {
            
            int curr=q.front();
            
            q.pop();
            
            vis[curr]=1;
            
            if(arr[curr]==0)return true;
            
            if(curr+arr[curr]>=0 and curr+arr[curr]<n and !vis[curr+arr[curr]])
            {
                q.push(curr+arr[curr]);
            }
            
            if(curr-arr[curr]>=0 and curr-arr[curr]<n and !vis[curr-arr[curr]])
            {
                q.push(curr-arr[curr]);
            }
        }
        return false;
    }
};