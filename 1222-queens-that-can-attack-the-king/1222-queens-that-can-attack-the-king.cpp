class Solution
{
    public:
        vector<vector < int>> queensAttacktheKing(vector<vector < int>> &queens, vector< int > &king)
        {

           	//Approach is king ke 8 directions me jao aur udhar se nearest q ko pick karo 
            

            vector<vector < int>> ans;

            set<vector < int>> set;

            for (auto itr: queens)
            {
                set.insert(itr);
            }

        int r=king[0];
        int c=king[1];
        
        for(int i=r+1;i<8;i++)
        {
            if(set.count({i,c}))
            {
                ans.push_back({i,c});
                break;
            }
        }
        for(int i=r-1;i>=0;i--)
        {
            if(set.count({i,c}))
            {
                ans.push_back({i,c});
                break;
            }
        }
        for(int i=c+1;i<8;i++)
        {
            if(set.count({r,i}))
            {
                ans.push_back({r,i});
                break;
            }
        }
        for(int i=c-1;i>=0;i--)
        {
            if(set.count({r,i}))
            {
                ans.push_back({r,i});
                break;
            }
        }
        int i=r,j=c;
        while(i<8&&j<8)
        {
            if(set.count({i,j}))
            {
                ans.push_back({i,j});
                break;
            }
            i++;
            j++;
        }
        i=r;
        j=c;
        while(i<8&&j>=0)
        {
            if(set.count({i,j}))
            {
                ans.push_back({i,j});
                break;
            }
            i++;
            j--;
        }
        i=r;
        j=c;
        while(i>=0&&j<8)
        {
            if(set.count({i,j}))
            {
                ans.push_back({i,j});
                break;
            }
            i--;
            j++;
        }
        i=r;
        j=c;
        while(i>=0&&j>=0)
        {
            if(set.count({i,j}))
            {
                ans.push_back({i,j});
                break;
            }
            i--;
            j--;
        }
        return ans;
    }
        
};