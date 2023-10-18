class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        
        const int n=grid.size();
        unordered_map<string, int> hash; //string to its count
        int result=0;
        for(int row=0; row<n; ++row) {
            string s;
            for(int i=0;i<n;++i) s+=to_string(grid[row][i])+".";
            hash[s]++;
        }
        for(int col=0; col<n; ++col) {
            string s;
            for(int i=0;i<n;++i) s+=to_string(grid[i][col])+".";
            if (hash.count(s)>0) {
                result+=hash[s];
            }
        }
        return result;
    }
};