class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        
     ///why to use sliding window when i can directly use map;
         //10 10 len ki string banao aur map me update karo uski frequency betu 
        
        int n=s.length();
        
        unordered_map<string,int>map;
        
        //chalo map ko fill karte hai jii
        
        for(int i=0;i<n;i++)
        {
            int j=i;
            string str;
            while(j<i+10 and j<n)
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