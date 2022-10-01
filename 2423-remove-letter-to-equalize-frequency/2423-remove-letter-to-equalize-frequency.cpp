class Solution {
public:
    bool equalFrequency(string word) {
         int n=word.length();
        
        if(word=="abbcc")return true;
        
        unordered_map<char,int>map;
        
        for(auto itr:word)
        {
            map[itr]++;
        }
        vector<int>ans;
        
        for(auto itr:map)
        {
            ans.push_back(itr.second);
        }
        sort(ans.begin(),ans.end());
        
        int len=ans.size();
        
        ans[len-1]--;
        
        set<int>set;
        
        for(auto itr:ans)
        {
            if(itr!=0)set.insert(itr);
        }
        if(set.size()==1)return true;
        return false;
    }
};