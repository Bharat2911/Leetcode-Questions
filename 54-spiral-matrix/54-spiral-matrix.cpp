class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        int row=matrix.size();
        int col=matrix[0].size();
        
        int row1=0;
        int row2=row-1;
        
        int col1=0;
        int col2=col-1;
        
        int direction=0;
        
        vector<int>ans;
        
        
        while(row1<=row2 and col1<=col2)
        {
            if(direction==0)
            {
                for(int i=col1;i<=col2;i++)
                {
                    ans.push_back(matrix[row1][i]);
                }
                row1++;
            }
            
            if(direction==1)
            {
                for(int i=row1;i<=row2;i++)
                {
                    ans.push_back(matrix[i][col2]);
                }
                col2--;
            }
            if(direction==2)
            {
                for(int i=col2;i>=col1;i--)
                {
                    ans.push_back(matrix[row2][i]);
                }
                row2--;
            }
            if(direction==3)
            {
                for(int i=row2;i>=row1;i--)
                {
                    ans.push_back(matrix[i][col1]);
                }
                col1++;
            }
            
            direction=(direction+1)%4;
        }
        return ans;
    }
};