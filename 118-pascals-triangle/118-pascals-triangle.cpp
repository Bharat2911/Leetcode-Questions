class Solution {
public:
    vector<vector<int>> generate(int n) {
        
        //for every row starting and ending elemnt is 1 
        vector<vector<int>>ans={{1}};
        
        if(n==1)return ans;
        
        ans.push_back({1,1});//thsi is the case when n=2;
        
        for(int i=2;i<n;i++)
        {
            vector<int>temp={1};//start of evrey row is 1
            
            for(int j=1;j<i;j++)
            {
                temp.push_back({ans[i-1][j-1]+ans[i-1][j]});
            }
            temp.push_back(1);//endeing ele of every row is1
            
            ans.push_back(temp);
        }
        return ans;
    }
};