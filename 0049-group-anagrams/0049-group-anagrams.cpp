class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<string,vector<string>>map;
        
        for(int i=0;i<strs.size();i++)
        {
            string str=strs[i];
            
            sort(str.begin(),str.end());
            
            map[str].push_back(strs[i]);
        }
        
        vector<vector<string>>ans;
        
        for(auto itr:map)
        {
            ans.push_back(itr.second);
        }
        
        return ans;
    }
};