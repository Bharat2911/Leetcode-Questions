class Solution {
public:
    int numRabbits(vector<int>& arr) {
        
        //basically in this we will try to make the groups
        int n=arr.size();
        
        unordered_map<int,int>map;//map will help us to make tht egoup
        for(auto itr:arr)
        {
            map[itr]++;
        }
        int count=0;
        
        
        for(auto itr:map)
        {
            int total_ele=itr.first+1;
            
            int group= (int)ceil((itr.second*1.0)/total_ele);
            
            count+=group*total_ele;
        }
        return count;
    }
};