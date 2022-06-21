// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// Function to determine if graph can be coloured with at most M colours such
// that no two adjacent vertices of graph are coloured with same colour.
bool issafe(int node,int color[],int m,int n,bool graph[101][101],int col)
{
    for(int k=0;k<n;k++)
    {
        if(k!=node and graph[k][node]==1 and color[k]==col)
        {
            return false;
        }
    }
    return true;
}
bool solve(int start,int m,int n,bool graph[101][101],int color[])
{
    if(start==n)//means we reach the end
    {
        return true;
    }
    for(int i=1;i<=m;i++)
    {
        //if it is safe tto color then we willcolor it
        if(issafe(start,color,m,n,graph,i))
        {
            color[start]=i;
            
           if(solve(start+1,m,n,graph,color) ) return true;
            
            color[start]=0;//this is my backtraking step its imp for try all possbile combinations
        }
    }
    return false;
}
bool graphColoring(bool graph[101][101], int m, int n) {
    // your code here
    
    //will try out all possbile color color for each node
    int color[n]={0};
    
    if(solve(0,m,n,graph,color))
    {
        return true;
    }
    return false;
    
}

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        cout << graphColoring(graph, m, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends