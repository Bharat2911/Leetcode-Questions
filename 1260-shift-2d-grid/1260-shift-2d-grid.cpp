class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        
        int row=grid.size();
        int col=grid[0].size();
        
        int total_ele=row*col;
        
        k=k%total_ele;
        
        if(k==0)return grid;//base case
        
        
        while(k--)
        {
            int temp=grid[0][0];
            
            for(int i=0;i<row;i++)
            {
                for(int j=0;j<col;j++)
                {
                    swap(temp,grid[i][j]);
                }
            }
            swap(temp,grid[0][0]);
        }
        return grid;
        
    }
};