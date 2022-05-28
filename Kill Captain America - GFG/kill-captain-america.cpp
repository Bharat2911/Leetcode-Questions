// { Driver Code Starts
#include <bits/stdc++.h>
 
using namespace std;
 

 // } Driver Code Ends
class Solution{
public:
    int captainAmerica(int N, int M, vector<vector<int>> &V){
        // Code Here
         vector<bool> INS(N + 1, false);  // visit INs edges
        vector<bool> OUTS(N + 1, false);  // visit OUTs edges
        vector<vector<int>> adjOUTS(N + 1); 
        vector<vector<int>> adjINS(N + 1);

        int from, to;
        for (int i = 0; i < M; i++) {
            from = V[i][0];
            to = V[i][1];
            adjINS[to].emplace_back(from);
            adjOUTS[from].emplace_back(to);
        }

        //Find last room from someroom (this case room 1)
        //follow outs edges starting from room 1.
        // ending room --> 'next' it is posible a wanted room
        // if there is no outs from room 1 --> posible wanted room
        vector<int> stack(N + 1);
        int index_stack = 0;
        int count = 0;
        int next = 0;
        stack[index_stack++] = 1;
        while (index_stack > 0) {
            next = stack[--index_stack];
            for (auto x : adjOUTS[next]) {
                if (OUTS[x] == false) {
                    OUTS[x] = true;
                    count++;
                    stack[index_stack++] = x;
                }
            }
        }

        // next <--  last room
        // check if verify all room gets this last room (next)
        count = 0;
        index_stack = 0;
        stack[index_stack++] = next;  
        int a = 0;
        while (index_stack > 0) {
            a = stack[--index_stack];
            for (auto x : adjINS[a]) {
                if (INS[x] == false) {
                    INS[x] = true;
                    count++;
                    stack[index_stack++] = x;
                }
            }
        }
        if (count < N - 1) {
            return 0;  // no unify topology for condition
        }

        // reset visitd outs vector
        for (int i = 0; i < N + 1; i++) OUTS[i] = false;

        // counting all reached room from wanted room 'next'
        index_stack = 0;
        stack[index_stack++] = next;
        count = 0;
        while (index_stack > 0) {
            next = stack[--index_stack];
            for (auto x : adjOUTS[next]) {
                if (OUTS[x] == false) {
                    OUTS[x] = true;
                    count++;
                    stack[index_stack++] = x;
                }
            }
        }

        return max(count, 1);
    } 
};

// { Driver Code Starts.
 

int main() {
    int t;cin >> t;
    while(t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> v(m+1);
        for(int i=0;i<m;i++){
            int a, b;cin >> a >> b;
            v[i].push_back(a);
            v[i].push_back(b);
        }
        
        Solution obj;
        cout << obj.captainAmerica(n, m, v) << endl;
    }
 
}  // } Driver Code Ends