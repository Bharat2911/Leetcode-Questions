class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        
        int n=nums.size();
        
        unordered_map<int,int>map;
        int count=0;
        
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int product=nums[i]*nums[j];
                
                
                if(map.find(product)!=map.end())
                {
                    count+=map[product];
                }
                map[product]++;
            }
        }
        return count*8;//total 8 permutaion are possibles
        
    }
};