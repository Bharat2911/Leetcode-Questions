class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        
        unordered_map<int,int>map;
        
        for(auto itr:tasks)map[itr]++;
        int count=0;
        
        for(auto itr:map)
        {
            if(itr.second<2)return -1;
            
            if(itr.second%3==0)
            {
                count+=itr.second/3;
            }
            else
            {
                count+=(itr.second/3)+1;
            }
        }
        return count;
    }
};