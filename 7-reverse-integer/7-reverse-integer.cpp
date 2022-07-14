class Solution {
public:
    int reverse(int x) {
        
        //convert to strign 
        string str=to_string(x);
        
        
        //deal with the sign
        int sign=1;
        
        if(str[0]=='-')
        {
            sign=-1;
            
        }
        
        //reverse the strign 
        
        int low=0;
        int high=str.length()-1;
        
        while(low<high)
        {
            swap(str[low++],str[high--]);
        }
        
        
        //convert strign to integer again
        //stol ->string to long int
        
        long long ans=stol(str);
        
        if(ans<INT_MIN || ans>INT_MAX)return 0;
        
        return sign*ans;
        
    }
};