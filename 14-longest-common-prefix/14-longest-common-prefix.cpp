class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        
        string res=strs[0];
        
        int i=0;
        
        while(i<strs.size())
        {
            int j=0;
            
            string ans;
            
            int l=res.length();
            
            
            while(j<l and res[j]==strs[i][j])
            {
                ans+=res[j];
                j++;
            }
            
            res=ans;
            i++;
        }
        
        return res;
    }
};