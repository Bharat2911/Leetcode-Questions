class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& arr) {
        
        int distance=startFuel;
        
        int count=0;
        
        priority_queue<int>pq;
        
        for(int i=0;i<arr.size();i++)
        {
            int nextpos=arr[i][0];
            int fuel=arr[i][1];
            
            //we will push only when our distance is less than nextPos
            
            while(distance<nextpos)
            {
                if(pq.empty())return -1;
                
                int x=pq.top();
                pq.pop();
                
                distance+=x;
                count++;
            }
            
            pq.push(arr[i][1]);
        }
        while(distance <target)
        {
            if(pq.empty())return -1;
            
            int x=pq.top();
            pq.pop();
            distance+=x;
            count++;
        }
        return count;
    }
};