class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        int ef=0;
        int rf=0;
        
        int ans=0;
        
        for(int i=0;i<gas.size();i++)
        {
            ef+=gas[i]-cost[i];
            
            if(ef<0)
            {
                rf+=ef;
                
                ans=i+1;
                
                ef=0;
            }
        }
        if(ef+rf>=0)
        {
            return ans;
        }
        
        return -1;
    }
};