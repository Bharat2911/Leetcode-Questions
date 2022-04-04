class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& ans, int k) {
        
           sort(ans.begin(),ans.end());
        vector<vector<int>>v;
        
        int count=0;
        if(ans.size()<4)return{};
        for(int i=0;i<ans.size()-3;i++)
        {
            for(int j=i+1;j<ans.size()-2;j++)
            {
                int l=j+1;
                int r=ans.size()-1;
                
                
                while(l<r)
                {
                    vector<int>v2;
                    
                    if((long long)ans[i]+ans[j]+ans[l]+ans[r]==k)
                    {
                        count++;
                        v2.push_back(ans[i]);
                         v2.push_back(ans[j]);
                         v2.push_back(ans[l]);
                         v2.push_back(ans[r]);
                        
                        v.push_back(v2);
                        
                        l++;
                        r--;
                        
                    }
                    else if((long long)ans[i]+ans[j]+ans[l]+ans[r]<k)
                    {
                        l++;
                    }
                    else 
                    {
                        r--;
                    }
                }
            }
        }
       sort(v.begin(),v.end());
        v.erase(unique(v.begin(), v.end()), v.end());
        return v;
        
    }
};