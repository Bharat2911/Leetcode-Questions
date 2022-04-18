class Solution {
public:
    vector<int> partitionLabels(string s) {
        
        unordered_map<char,int>map;
        int n=s.length();
        
        //update the last position of each elelmnt int he ma[p
        vector<int>ans;
        int start=0;
        int end=0;
        
        for(int i=0;i<n;i++)
        {
            map[s[i]]=i;
        }
        
        for(int i=0;i<n;i++)
        {
            end=max(end,map[s[i]]);
            
            if(i==end)
            {
                ans.push_back(end-start+1);
                start=i+1;
            }
        }
        return ans;
    }
};