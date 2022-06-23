class Solution {
public:
    string getHint(string s, string g) {
        
        //x A y B
        //x->bulls
        //y->coes
        
        vector<int>arr1(26,0);
        vector<int>arr2(26,0);
        
        int bulls=0;
        int cows=0;
        
        for(int i=0;i<s.length();i++)
        {
            if(s[i]==g[i])
            {
                bulls++;
                
            }
            else
            {
                arr1[s[i]-'0']++;
                arr2[g[i]-'0']++;
                
            }
        }
        for(int i=0;i<26;i++)
        {
            cows+=min(arr1[i],arr2[i]);
        }
        
        string ans=to_string(bulls)+'A'+to_string(cows)+'B';
        
        return ans;
    }
};