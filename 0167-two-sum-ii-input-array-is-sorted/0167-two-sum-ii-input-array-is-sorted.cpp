class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int tar) {
        
        //approach 1->run two nested loop
        //T.C=O(n^2)
        //S.C=O(1)
        
//         int n=numbers.size();
        
//         vector<int>ans;
        
//         for(int i=0;i<n;i++)
//         {
//             for(int j=i+1;j<n;j++)
//             {
//                 if(i!=j)
//                 {
//                     if(numbers[i]+numbers[j]==target)
//                     {
//                         ans.push_back(i+1);
//                         ans.push_back(j+1);
                        
//                         break;
//                     }
//                 }
//             }
//         }
//         return ans;
        //approach->2 hashing
        //T.C=O(n)
        //S.C=O(n)
        
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