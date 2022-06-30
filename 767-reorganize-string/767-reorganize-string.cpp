class Solution {
public:
    string reorganizeString(string s) {
        
        //greedy thinking hain
        //arrange the max frequency char alternate follwed by second max frequency then third
        //max frequency 
        int n=s.length();
        
        //max heap
        priority_queue<pair<int,char>>pq;
        
        //map to store then freq of each char 
        unordered_map<char,int>map;
        
        for(auto itr:s)
        {
            map[itr]++;
        }
        
        //push in the pq
        
        for(auto itr:map)
        {
            pq.push({itr.second,itr.first});
        }
         string ans="";
        
        if(pq.size()==0)return ans;
        
        while(pq.size()>1)
        {
            int f1=pq.top().first;
            char char1=pq.top().second;
            pq.pop();
            
            ans+=char1;
            
            int f2=pq.top().first;
            char char2=pq.top().second;
            pq.pop();
            
            
            ans+=char2;
            
            if(f1-1>0)
            {
                pq.push({f1-1,char1});
            }
            if(f2-1>0)
            {
                pq.push({f2-1,char2});
            }
        }
        if(pq.size()==1 and pq.top().first==1)
        {
            ans+=pq.top().second;
        }
        if(pq.size()==1 and pq.top().first>1)
        {
            return "";
        }
        return ans;
    }
};