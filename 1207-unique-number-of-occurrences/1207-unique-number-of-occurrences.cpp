class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        
        int n=arr.size();
        
        unordered_map<int,int>map;
        
        for(auto itr:arr)
        {
            map[itr]++;
        }
        
        set<int>st;
        
        for(auto itr:map)
        {
            st.insert(itr.second);
        }
        if(st.size()==map.size())
        {
            return true;
        }
        return false;
    }
};