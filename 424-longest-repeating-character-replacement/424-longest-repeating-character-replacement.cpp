class Solution {
public:
    int characterReplacement(string s, int k) {
        
        //find the char with largest frequency bro then convert all the other character equal to that char
       //approach //sab element ko apan max frequency elements se change karenge 
        unordered_map<char,int>map;
        
        int n=s.length();
        int i=0;
        int j=0;
        int ans=0;
        int max_freq=0;
        
        while(j<n)
        {
            map[s[j]]++;
            max_freq=max(max_freq,map[s[j]]);
            
            if((j-i+1)-max_freq>k)
            {
                map[s[i]]--;
                i++;
            }
            
            ans=max(ans,j-i+1);
            j++;
        }
           return ans;
    }
};