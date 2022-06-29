class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        
        //brute force 
        //T.c=O(n^2)
        //s.c=O(n+n);
        
        
        vector<int>ans;
        
        //make a min heap  
        priority_queue<int>pq;
        
        
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[0].size();j++)
            {
                pq.push(matrix[i][j]);
                
                if(pq.size()>k)
                {
                    pq.pop();
                }
            }
        }
        return pq.top();
        
    }
};