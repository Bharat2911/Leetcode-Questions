class Solution {
public:
    int reverse(int x) {
        
     //convert integer to string 
        
        string str=to_string(x);
        
    //manage the sign 
        
        int sign=1;
        
        if(str[0]=='-')
        {
            sign=-1;
           
        }
        
     //reverse the string 
        
        int n=str.length();
        int low=0;
        int high=n-1;
        while(low<=high)
        {
            swap(str[low++],str[high--]);
        }
        
        //convert string to integer
        //stol ->convert string to long int
        
        if(stol(str)<INT_MIN || stol(str)>INT_MAX)return 0;//out of the bond condition
        
        
        return sign*stol(str);
    }
};