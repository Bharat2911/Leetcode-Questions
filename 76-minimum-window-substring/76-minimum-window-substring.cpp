class Solution
{
    public:
        string minWindow(string s, string t)
        {
            if(t.length()==0 || s.length()==0)return "";
        
        int i=0;
        int j=0;
        unordered_map<char,int>tmap;
        unordered_map<char,int>window;
        int count=0;
        int required=t.length();
        string ans;
        int len=INT_MAX;
        
        for(auto itr:t)
        {
            tmap[itr]++;
        }
        for(;j<s.length();j++)
        {
            char ch=s[j];
            
            window[ch]++;
            
            if(tmap.count(ch) and window[ch]<=tmap[ch])
            {
                count++;
                
                
            }
            while(count==required)
            {
                if(j-i+1<len)
                {
                    len=j-i+1;
                    ans=s.substr(i,len);
                }
                window[s[i]]--;
                if(tmap.count(s[i]) and window[s[i]]<tmap[s[i]])
                {
                    count--;
                }
                i++;
            }
        }
        return (len != INT_MAX) ? ans : "";
        }
};