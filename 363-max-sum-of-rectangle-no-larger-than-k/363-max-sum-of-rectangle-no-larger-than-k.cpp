class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        
          int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int> > presum(n, vector<int>(m, 0));
        for(int i = 0; i < n; i++) {
            int sum = 0;
            for(int j = 0; j < m; j++) {
                sum += matrix[i][j];
                presum[i][j] = sum;
            }
        }
        int ans = INT_MIN;
        for(int i = 0; i < m; i++) {
            for(int j = i; j < m; j++) {
                set<int> st;
                int sum = 0;
                st.insert(0);
                for(int l = 0; l < n; l++) {
                    int val = presum[l][j] - (i == 0 ? 0 : presum[l][i-1]);
                    sum += val;
                    auto it = st.lower_bound(sum-k);
                    if(it != st.end()) {
                        ans = max(ans, sum-*it);
                    }
                    st.insert(sum);
                }
            }
        }
        return ans;
    }
};