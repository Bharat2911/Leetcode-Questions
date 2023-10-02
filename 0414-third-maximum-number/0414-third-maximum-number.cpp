class Solution {
public:
    int thirdMax(vector<int>& nums) {
        
          int n = nums.size();
        long m1 = LONG_MIN;
        long m2 = m1, m3 = m1;

        for(auto i:nums){
           if(i>m1)
           {
               m3=m2;
               m2=m1;
               m1=i;
           }
           else if(i!=m1 && i>m2)
           {
               m3=m2;
               m2=i;
           }
           else if(i!=m1 && i!=m2 && i>m3)
           {
               m3=i;
           }
        }
        
        if(m2==m3 || m3==LONG_MIN)
            return m1;
        
        return m3;
    
        
        
    }
};