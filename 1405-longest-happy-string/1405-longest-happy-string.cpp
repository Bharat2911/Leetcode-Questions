class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        
         string ans;
        
        if(a==0 and b==0 and c==0)
        {
            return ans;
        }
        
        priority_queue<pair<int,char>>pq;
        
        if(a!=0)pq.push({a,'a'});
        
        if(b!=0)pq.push({b,'b'});
        
        if(c!=0)pq.push({c,'c'});
        
        while(pq.size()>1)
        {
            int f1=pq.top().first;
            char c1=pq.top().second;
            pq.pop();
            
            int f2=pq.top().first;
            char c2=pq.top().second;
            pq.pop();
            
            if(f1>1)
            {
                ans+=c1;
                ans+=c1;
                
                f1-=2;
                
               
            }
            else
            {
                ans+=c1;
                f1--;
            }
            
            if(f2>1 and f2>=f1)
            {
                ans+=c2;
                ans+=c2;
                
                f2-=2;
                
                
            }
            else
            {
                ans+=c2;
                f2--;
            }
            if(f1>0)
            {
                pq.push({f1,c1});
            }
            if(f2>0)
            {
                pq.push({f2,c2});
            }
        }
        if(!pq.empty())
        {
            int f=pq.top().first;
            char ch=pq.top().second;

            if(f>1)
            {
                ans+=ch;
                ans+=ch;
            }
            else
            {
                ans+=ch;
            }
        }
            
        return ans;
    }
};