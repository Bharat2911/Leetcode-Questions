class Solution {
public:
    vector<int> sumZero(int n) {
        
        // symmetric elemnts choosw kar0
        //+x,-x
        
        vector<int>ans;
        
        if(n&1)
        {
            ans.push_back(0);
            n--;
        }
        
        int i=1;
        
        while(n>0 and i<1001)
        {
            ans.push_back(i);
            ans.push_back(-i);
            i++;
            
            n-=2;
        }
        return ans;
    }
};