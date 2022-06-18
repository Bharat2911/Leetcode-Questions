class WordFilter {
public:
    //map will be storing the prefix and suffix with index
    unordered_map<string,int>map;
    
    WordFilter(vector<string>& words) {
        
        int index=0;
        for(auto word:words)
        {
            for(int i=0;i<=word.size();i++)
            {
                for(int j=0;j<=word.size();j++)
                {
                    string preSuff=word.substr(0,i)+'$'+word.substr(j);
                    
                    map[preSuff]=index;
                }
            }
             index++;
        }
       
    }
    
    int f(string prefix, string suffix) {
        
        string ans=prefix+'$'+suffix;
        
        if(map.find(ans)!=map.end()) 
        {
            return map[ans];
        }
        return -1;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */