class Solution {
public:
    int nextGreaterElement(int n) {
        
        //in this we will apply next permutaion concept
        
        string str=to_string(n);
        string s=str;
        
        int i;
        int j;
        
        for(i=str.length()-2;i>=0;i--)
        {
            if(str[i]<str[i+1])
            {
                break;
            }
        }
        if(i<0)
        {
            reverse(str.begin(),str.end());
        }
        else
        {
            for(j=str.length()-1;j>=0;j--)
            {
                if(str[j]>str[i])
                {
                    break;
                }
            }
            swap(str[i],str[j]);
            reverse(str.begin()+i+1,str.end());
        }
        if(str<=s)
        {
            return -1;
        }
        long long ans=stoll(str);
        if(ans<INT_MIN || ans>INT_MAX)return -1;
        
        return ans;
    }
};