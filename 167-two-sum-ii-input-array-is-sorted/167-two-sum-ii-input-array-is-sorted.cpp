class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int tar) {
        
        // o(n),O(n); ->map approach hai
        
//         unordered_map<int,int>map;
//         int n=arr.size();
        
//         for(int i=0;i<n;i++)
//         {
//             map[arr[i]]=i+1;
//         }
//         vector<int>ans;
        
//         for(int i=0;i<n;i++)
//         {
//                int x=tar-arr[i];
            
//             if(map.find(x)!=map.end())
//             {
//                 ans.push_back(i+1);
//                 ans.push_back(map[x]);
//                 break;
                
//             }
            
//         }
//         return ans;
        
        
        //since araay is sorted so use that concpet here 
        //means two pointer approach 
        //T.C O(N)
        //S.C O(1) //constant space lega two pointer approach
        
        vector<int>ans;
        
        int n=arr.size();
        
        int i=0;
        int j=n-1;
        
        while(i<j and j>=0)
        {
            if(arr[i]+arr[j]==tar)
            {
                ans.push_back(i+1);
                ans.push_back(j+1);
                i++;
                j--;
                break;
            }
            else if(arr[i]+arr[j]>tar)
            {
                j--;
            }
            else
            {
                i++;
            }
        }
        
        return ans;
    }
};