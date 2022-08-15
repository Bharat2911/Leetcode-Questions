class Solution {
public:
    int romanToInt(string s) {
        
        unordered_map<char,int>map;
            
            int n=s.length();
        
            map.insert({'I',1});
         map.insert({'V',5});
         map.insert({'X',10});
         map.insert({'L',50});
         map.insert({'C',100});
         map.insert({'D',500});
         map.insert({'M',1000});
        
        int ans=map[s[n-1]];
        
        for(int i=n-2;i>=0;i--)
        {
            if(map[s[i]]<map[s[i+1]])
            {
                ans-=map[s[i]];
            }
            else
            {
                ans+=map[s[i]];
            }
        }
        return ans;
    }
};