class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        vector<pair<int,int>>v;
        int n=gas.size();
        
        for(int i=0;i<n;i++)
        {
            v.push_back({gas[i],cost[i]});
        }
        int extra_fuel=0;
        int required_fuel=0;
        
        int start=0;
        
        for(int i=0;i<n;i++)
        {
            extra_fuel+=(v[i].first-v[i].second);
            
            
            if(extra_fuel<0)//we required fuel at that point
            {
                start=i+1;
                required_fuel+=extra_fuel;
                extra_fuel=0;
            }
        }
        if(extra_fuel+required_fuel>=0)return start;
        return -1;
    }
};