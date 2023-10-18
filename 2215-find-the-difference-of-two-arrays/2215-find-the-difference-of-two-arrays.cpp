class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        
        vector<vector<int>>ans;
        
        vector<int>v1;
        vector<int>v2;
        
        set<int>s1;
        set<int>s2;
        
        unordered_map<int,int>m1;
        
        unordered_map<int,int>m2;
        
        for(auto itr:nums1)
        {
            m1[itr]++;
        }
        
        for(auto itr:nums2)
        {
            m2[itr]++;
        }
        
        for(auto itr:nums1)
        {
            if(m2.find(itr)==m2.end())
            {
                s1.insert(itr);
            }
            
        }
         for(auto itr:nums2)
        {
            if(m1.find(itr)==m1.end())
            {
                s2.insert(itr);
            }
            
        }
        for(auto itr:s1)v1.push_back(itr);
        for(auto itr:s2)v2.push_back(itr);
        
        
        ans.push_back(v1);
        ans.push_back(v2);
        
        return ans;
    }
};