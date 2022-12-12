class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        //approach 1-> brute force
        //T.C=O(n^2)
        //S.C=O(1)
        
//         vector<int>ans;
//         int n=nums.size();
        
//         for(int i=0;i<n;i++)
//         {
//             int pro=1;
            
//             for(int j=0;j<n;j++)
//             {
//                 if(i!=j)
//                 {
//                     pro*=nums[j];
//                 }
//             }
//             ans.push_back(pro);
//         }
        
//         return ans;
        
//         approach 2->T.C==O(n)
                    // S.C=O(n)
        
        int n=nums.size();
        
        vector<int>right(n);
        
        vector<int>left(n);
        
        
        left[0]=nums[0];
        right[n-1]=nums[n-1];
        
        for(int i=1;i<n;i++)
        {
            left[i]=left[i-1]*nums[i];
        }
        for(int i=n-2;i>=0;i--)
        {
            right[i]=right[i+1]*nums[i];
        }
        
        vector<int>ans;
        
        for(int i=0;i<n;i++)
        {
            if(i==0)
            {
                ans.push_back(right[i+1]);
            }
            else if(i==n-1)
            {
                ans.push_back(left[i-1]);
            }
            else
            {
                ans.push_back(left[i-1]*right[i+1]);
            }
        }
        return ans;
    }
};