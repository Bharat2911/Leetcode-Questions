class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        
        int len=s.length();
        
        unordered_map<string,int>map;
        
        for(int i=0;i<len;i++)
        {
            int j=i;
            
            string str;
            
            while(j<i+10 and j<len)
            {
                str+=s[j];
                
                j++;
            }
            
            map[str]++;
        }
        
        vector<string>ans;
        
        for(auto itr:map)
        {
            if(itr.second>1)
            {
                ans.push_back(itr.first);
            }
        }
        return ans;
    }
};