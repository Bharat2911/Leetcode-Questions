class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        
        vector<int>pos;
        vector<int>neg;
        vector<int>ans;
        
        for(auto itr:nums)
        {
            if(itr<0)
            {
                neg.push_back(itr);
            }
            else
            {
                pos.push_back(itr);
            }
        }
        int i=0;
        
        while(i<pos.size())
        {
            ans.push_back(pos[i]);
            ans.push_back(neg[i]);
            i++;
        }
        return ans;
    }
};