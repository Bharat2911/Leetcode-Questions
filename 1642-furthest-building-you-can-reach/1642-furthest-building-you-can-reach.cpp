class Solution {
public:
    int furthestBuilding(vector<int>& arr, int b, int l) {
        
        //if think greedly to bade distance ke liye will use ladder and for small distance will use bricks
         priority_queue <int, vector<int>, greater<int> > pq;
         int bsum=0;
        
        
        for(int i=0;i<arr.size()-1;i++)
        {
            int diff=arr[i+1]-arr[i];
            
            if(diff>0)
            {
                pq.push(diff);
            }
            if(pq.size()>l)
            {
                b-=pq.top();
                pq.pop();
                
            }
            if(b<0)
            {
                return i;
            }
        }
        //otherwise i will reach the end so return n-1;
        
        return arr.size()-1;
        
    }
};