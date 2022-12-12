class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        vector<vector<string>>ans;
        
        unordered_map<string,vector<string>>map;
        
        for(auto itr:strs)
        {
            string str=itr;
            
            sort(str.begin(),str.end());
            
            map[str].push_back(itr);
        }
        
        for(auto itr:map)
        {
            ans.push_back(itr.second);
        }
        
        return ans;
    }
};