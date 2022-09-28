class Solution {
public:
    vector<int>lps(string&str)
        {
            int n=str.length();
            
            vector<int>v(n,0);
            
            int i=1;
            
            int j=0;
            
            while(i<n)
            {
                if(str[i]==str[j])
                {
                    v[i]=j+1;
                    i++;
                    j++;
                }
                else
                {
                    if(j==0)
                    {
                        i++;
                    }
                    else
                    {
                        j=v[j-1];
                    }
                }
            }
            return v;
        }
    int strStr(string haystack, string needle) {
        
        string str=needle+"$"+haystack;
        int n=needle.length();
        
        vector<int>arr=lps(str);
            
            vector<int>ans;
            
            // for(auto itr:arr)
            // {
            //     cout<<itr<<" ";
            // }
            for(int i=0;i<str.length();i++)
            {
                if(arr[i]==n)//means pattern is present
                {
                   return i-n-(n-1)-1;
                }
                
            }
        return -1;
    }
};