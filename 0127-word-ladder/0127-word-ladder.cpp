class Solution {
public:
    bool is_posible(string &s1,string&s2)
    {
        int i=0;
        int count=0;
        
        while(i<s1.length())
        {
            if(s1[i]!=s2[i])
            {
                count++;
            }
            i++;
        }
        if(count==1)return true;
        return false;
    }
    int ladderLength(string start, string end, vector<string>& list) {
        
        unordered_map<string,vector<string>>adj;
        
        for(int i=0;i<list.size();i++)
        {
            for(int j=i+1;j<list.size();j++)
            {
                if(is_posible(list[i],list[j]))
                {
                    adj[list[i]].push_back(list[j]);
                    adj[list[j]].push_back(list[i]);
                }
            }
        }
        for(int i=0;i<list.size();i++)
        {
            if(is_posible(start,list[i]))
            {
                adj[start].push_back(list[i]);
                adj[list[i]].push_back(start);
            }
        }
        set<string>vis;
        queue<string>q;
        q.push(start);
        vis.insert(start);
        
        int count=0;
        
        while(!q.empty())
        {
            int sz=q.size();
            count++;
            
            while(sz--)
            {
                string str=q.front();
                q.pop();
                
                if(str==end)
                {
                    return count;
                }
                for(auto itr:adj[str])
                {
                    if(!vis.count(itr))
                    {
                        vis.insert(itr);
                        q.push(itr);
                    }
                }
            }
        }
        return 0;
    }
};