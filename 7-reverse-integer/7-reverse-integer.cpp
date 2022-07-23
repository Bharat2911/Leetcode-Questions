class Solution {
public:
    int reverse(int x) {
        
        string str=to_string(x);
        
        //manage the sign
        int sign=1;
        if(str[0]=='-')
        {
            sign=-1;
            
        }
        //reverse the string 
        int low=0;
        int high=str.length()-1;
        
        while(low<high)
        {
            swap(str[low++],str[high--]);
        }
        
        //again convert to integer
        long long ans=stol(str);
        
        if(ans<INT_MIN || ans>INT_MAX)return 0;
        
        return ans*sign;
        
    }
};