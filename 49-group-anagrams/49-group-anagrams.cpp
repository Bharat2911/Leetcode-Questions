class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        vector<vector<string>>ans;
        
        unordered_map<string,vector<string>>map;
        
        int n=strs.size();
        
        for(int i=0;i<n;i++)
        {
            string st=strs[i];
            
            sort(st.begin(),st.end());
            
            map[st].push_back(strs[i]);
        }
        
        for(auto itr:map)
        {
            ans.push_back(itr.second);
        }
        return ans;
    }
};