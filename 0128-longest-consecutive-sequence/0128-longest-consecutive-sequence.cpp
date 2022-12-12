class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        //approach 1->brute force 
        // tC==O(nlog n)+O(n^2)==O(n^2)
        
        
//         int n=nums.size();
        
//         sort(nums.begin(),nums.end());
        
//         int ans=0;
        
//         for(int i=0;i<n;i++)
//         {
//             int prev=nums[i];
//             int count=1;
            
//             for(int j=i+1;j<n;j++)
//             {
//                 if(nums[j]-prev==1)
//                 {
//                     prev=nums[j];
//                     count++;
//                 }
//             }
//             ans=max(ans,count);
//         }
//         return ans;
        
        //approach->2 hashing
        //T>C=O(n)//itratin once
        //S.C=O(n)//using the set
        
        int n=nums.size();
        
        set<int>set;
        
        for(auto itr:nums)
        {
            set.insert(itr);
        }
        int ans=0;
        
        for(auto itr:nums)
        {
            if(!set.count(itr-1))
            {
                int curr=itr;
                int count=1;
                
                while(set.count(curr+1))
                {
                    count++;
                    curr++;
                }
                
                ans=max(ans,count);
            }
            
            
        }
        return ans;
    }
};