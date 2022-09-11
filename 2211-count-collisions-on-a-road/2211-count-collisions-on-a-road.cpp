class Solution {
public:
    int countCollisions(string s) {
        
        
        int n=s.length();
        
        vector<pair<char,int>>ans;
        
        for(int i=0;i<n;i++)
        {
            int count=1;
            while(i+1<n and s[i]==s[i+1])
            {
                count++;
                i++;
            }
            ans.push_back({s[i],count});
        }
        // for(auto itr:ans)
        // {
        //     cout<<itr.first<<"-"<<itr.second<<" ";
        // }
        int x=0;
        
        for(int i=0;i<ans.size()-1;i++)
        {
            //check for three conditions
            if(ans[i].first=='R' and ans[i+1].first=='L')
            {
                x+=ans[i].second+ans[i+1].second;
            }
            else if(ans[i].first=='R' and ans[i+1].first=='S')
            {
                x+=ans[i].second;
            }
            else if(ans[i].first=='S' and ans[i+1].first=='L')
            {
                x+=ans[i+1].second;
            }
        }
        return x;
    }
};