class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        
        int n=stones.size();
        
        priority_queue<int>pq;
        
        for(int i=0;i<n;i++)
        {
            pq.push(stones[i]);
        }
        while(pq.size()>1)
        {
            int top1=pq.top();
            pq.pop();
            
            int top2=pq.top();
            pq.pop();
            
            if(top1!=top2)
            {
                pq.push(abs(top1-top2));
            }
        }
        if(pq.empty())return 0;
        return pq.top();
        
        
    }
};