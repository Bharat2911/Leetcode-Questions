class Solution {
public:
    bool is_diff(string &a,string&b)
    {
        int count=0;
        
        for(int i=0;i<a.length();i++)
        {
            if(a[i]!=b[i])
            {
                count++;
                
            }
        }
        if(count==1)return true;
        else return false;
        
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        unordered_map<string,vector<string>>adj;
        
        //basic approach of mine is to do bfs
        
        int n=wordList.size();
        
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(is_diff(wordList[i],wordList[j]))
                {
                    adj[wordList[i]].push_back(wordList[j]);
                    adj[wordList[j]].push_back(wordList[i]);
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            if(is_diff(beginWord,wordList[i]))
            {
                adj[beginWord].push_back(wordList[i]);
                adj[wordList[i]].push_back(beginWord);
            }
        }
        
        set<string>vis;
        
        queue<pair<string,int>>q;
        
        q.push({beginWord,1});
        
        vis.insert(beginWord);
        
        while(!q.empty())
        {
            string word=q.front().first;
            int level=q.front().second;
            
            q.pop();
            
            for(auto itr:adj[word])
            {
                if(vis.find(itr)==vis.end())
                {
                    vis.insert(itr);
                    q.push({itr,level+1});
                }
                if(itr==endWord)
                {
                    return level+1;
                }
            }
        }
        return 0;
    }
};