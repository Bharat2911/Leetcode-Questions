class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        
        //fin the product hen search it nto the map
        unordered_map<int,int>map;
        
        int n=nums.size();
        int product=0;
        int count=0;
        
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                product=nums[i]*nums[j];
                
                if(map.find(product)!=map.end())
                {
                    count+=map[product];
                }
                map[product]++;
            }
        }
        cout<<count;
        return count*8;
    }
};