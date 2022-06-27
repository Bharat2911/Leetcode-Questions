class Solution {
public:
    string reverse_str(string&temp)
    {
        for(int i=0;i<temp.size();i++)
        {
            if(temp[i]=='0')
            {
                temp[i]='1';
            }
            else
            {
                temp[i]='0';
            }
            
            
        }
        reverse(temp.begin(),temp.end());
        return temp;
    }
    string get_str(int n)
    {
        if(n==1)
        {
            return "0";
        }
        string temp=get_str(n-1);
        
        return temp+"1"+reverse_str(temp);
    }
    char findKthBit(int n, int k) {
        
        string ans=get_str(n);
        
        return ans[k-1];
        
    }
};