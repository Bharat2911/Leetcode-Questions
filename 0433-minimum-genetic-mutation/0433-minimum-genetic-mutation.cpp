class Solution {
public:
    bool is_safe(string&str,string&ptr)
    {
        int count=0;
        int n=str.length();
        int i=0;
        
        while(i<n )
        {
            if(str[i]!=ptr[i])
            {
                count++;
            }
            i++;
        }
        if(count==1)return true;
        return false;
    }
    int minMutation(string start, string end, vector<string>& bank) {
        
        unordered_map<string,vector<string>>adj;
        
        //fill the adj list
        
        for(int i=0;i<bank.size();i++)
        {
            for(int j=i+1;j<bank.size();j++)
            {
                if(is_safe(bank[i],bank[j]))
                {
                    adj[bank[i]].push_back(bank[j]);
                    
                    adj[bank[j]].push_back(bank[i]);
                }
            }
        }
        for(int i=0;i<bank.size();i++)
        {
            if(is_safe(bank[i],start))
            {
                adj[start].push_back(bank[i]);
                adj[bank[i]].push_back(start);
            }
        }
        
        queue<string>q;
        
        int count=0;
        
        set<string>vis;
        
        vis.insert(start);
        
        q.push(start);
        
        while(!q.empty())
        {
            int sz=q.size();
            
            while(sz--)
            {
                string temp=q.front();
                q.pop();
                
                if(temp==end)
                {
                    return count;
                }
                
                for(auto itr:adj[temp])
                {
                    if(!vis.count(itr))
                    {
                        vis.insert(itr);
                        q.push(itr);
                    }
                }
            }
            count++;
        }
        return -1;
    }
};