class Solution {
public:
    string frequencySort(string s) {
        
        int n=s.length();
        
        unordered_map<char,int>map;
        
        priority_queue<pair<int,char>>pq;
        
        string ans="";
        
        for(auto itr:s)
        {
            map[itr]++;
        }
        for(auto itr:map)
        {
            pq.push({itr.second,itr.first});
        }
        while(!pq.empty())
        {
            int freq=pq.top().first;
            
            char ch=pq.top().second;
            
            pq.pop();
            
            for(int i=0;i<freq;i++)
            {
                ans+=ch;
            }
        }
        return ans;
    }
};