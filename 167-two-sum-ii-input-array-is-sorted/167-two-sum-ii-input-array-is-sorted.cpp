class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int tar) {
        
        // o(n),O(n); ->map approach hai
        
        unordered_map<int,int>map;
        int n=arr.size();
        
        for(int i=0;i<n;i++)
        {
            map[arr[i]]=i+1;
        }
        vector<int>ans;
        
        for(int i=0;i<n;i++)
        {
               int x=tar-arr[i];
            
            if(map.find(x)!=map.end())
            {
                ans.push_back(i+1);
                ans.push_back(map[x]);
                break;
                
            }
            
        }
        return ans;
        
        
    }
};