class Solution {
public:
    string reorganizeString(string s) {
        
        
        int n=s.length();
        
        unordered_map<char,int>map;
        
        priority_queue<pair<int,char>>pq;
        
        for(auto itr:s)
        {
            map[itr]++;
        }
        
        for(auto itr:map)
        {
            pq.push({itr.second,itr.first});
        }
        
        string ans="";
        
        while(pq.size()>1)
        {
            int f1=pq.top().first;
            int ch1=pq.top().second;
            
            pq.pop();
            
            int f2=pq.top().first;
            char ch2=pq.top().second;
            
            pq.pop();
            
            if(f1>1)
            {
                ans+=ch1;
                
                f1--;
                
                pq.push({f1,ch1});
            }
            else
            {
                ans+=ch1;
                
                f1--;
            }
            
            if(f2>1)
            {
                ans+=ch2;
                
                f2--;
                
                pq.push({f2,ch2});
            }
            else
            {
                ans+=ch2;
                
                f2--;
            }
        }
        if(!pq.empty() and pq.top().first>1)
        {
            return "";
        }
        if(!pq.empty() and pq.top().first==1)
        {
            ans+=pq.top().second;
        }
        
        return ans;
    }
};