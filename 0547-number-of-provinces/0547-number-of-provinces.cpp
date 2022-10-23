class disjoint{
    // vector<int>parent,size;

    public:
     vector<int>parent,size;
    disjoint(int n)
    {
        parent.resize(n+1);
        size.resize(n+1,1);

        for(int i=0;i<=n;i++)
        {
            parent[i]=i;
        }

    }
    int findparent(int u)
    {
        if(u==parent[u])
        {
            return u;
        }
        return parent[u]=findparent(parent[u]);
    }
    void unionbysize(int u,int v)
    {
        int pu=findparent(u);

        int pv=findparent(v);

        if(pu==pv)return;

        if(size[pu]<size[pv])
        {
            parent[pu]=pv;
            size[pv]+=size[pu];
        }
        else
        {
            parent[pv]=pu;
            size[pu]+=pv;
        }
    }
};
class Solution {
public:
    int findCircleNum(vector<vector<int>>& adj) {
        
        int n=adj.size();
        
        disjoint dv(n);
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(adj[i][j]==1)
                {
                    dv.unionbysize(i,j);
                }
            }
        }
        int count=0;
        
        for(int i=0;i<n;i++)
        {
            if(dv.parent[i]==i)
            {
                count++;
            }
        }
        return count;
    }
};