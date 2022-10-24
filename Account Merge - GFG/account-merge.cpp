//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class disjoint
{

    public:
        vector<int> parent;

    vector<int> size;

    disjoint(int n)
    {
        parent.resize(n + 1);
        size.resize(n + 1, 1);

        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
    }

    int findparent(int node)
    {
       	//this is the function that will give us the ultimate parent
        if (node == parent[node])
        {
            return node;
        }

        return parent[node] = findparent(parent[node]);
    }
    void unionbysize(int u, int v)
    {
        int pu = findparent(u);
        int pv = findparent(v);

        if (pu == pv) return;

        if (size[pu] < size[pv])
        {
           	//always smaller get attached to bigger
            parent[pu] = pv;
            size[pv] += size[pu];
        }
        else
        {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};
class Solution{
  public:
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts) {
        // code here
        
          int n = accounts.size();

            disjoint dv(n);

            unordered_map<string, int> map;

            for (int i = 0; i < n; i++)
            {
                for (int j = 1; j < accounts[i].size(); j++)
                {
                    if (map.find(accounts[i][j])== map.end())	//means its not present in map
                    {
                        map[accounts[i][j]] = i;
                    }
                    else
                    {
                        dv.unionbysize(i, map[accounts[i][j]]);
                    }
                }
            }
            vector<string> mail[n];

            for (auto itr: map)
            {
                string str = itr.first;

                int idx = dv.findparent(itr.second);

                mail[idx].push_back(str);
            }

            vector<vector < string>> ans;

            for (int i = 0; i < n; i++)
            {
                if (mail[i].size() != 0)
                {
                    sort(mail[i].begin(), mail[i].end());
                    
                    vector<string>temp;
                    
                    temp.push_back(accounts[i][0]);
                    
                    for(auto itr:mail[i])
                    {
                        temp.push_back(itr);
                    }
                    
                    ans.push_back(temp);
                }
            }
            return ans;
        
    }
};


//{ Driver Code Starts.
int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    vector<vector<string>> accounts;

    for (int i = 0; i < n; i++)
    {
      vector<string> temp;
      int x;
      cin >> x;

      for (int j = 0; j < x; j++)
      {
        string s1;
        cin >> s1;
        temp.push_back(s1);
      }
      accounts.push_back(temp);
    }

    Solution obj;
    vector<vector<string>> res = obj.accountsMerge(accounts);
    sort(res.begin(), res.end());
    cout << "[";
    for (int i = 0; i < res.size(); ++i)
    {
      cout << "[";
      for (int j = 0; j < res[i].size(); j++)
      {
        if (j != res[i].size() - 1)
          cout << res[i][j] << ","
               << " ";
        else
          cout << res[i][j];
      }
      if (i != res.size() - 1)
        cout << "], " << endl;
      else
        cout << "]";
    }
    cout << "]"
         << endl;
  }
}
// } Driver Code Ends