class Solution {
public:
    int countSubstrings(string s) {
        
        //usingt he even odd methos 
        //choose the center then usse palindrome banao ek baar odd length ke then even length ke
        //even odd method
        int n=s.length();
        if(n==0 || n==1)
        {
            return n;
        }
        int count=0;
        
        for(int i=0;i<n;i++)
        {
            //odd len
            int j=i;
            int k=i;
            
            while(j>=0 and k<n and s[j]==s[k])
            {
                j--;
                k++;
                count++;
                
            }
            
            j=i;
            k=i+1;
            
            while(j>=0 and k<n and s[j]==s[k])
            {
                j--;
                k++;
                count++;
            }
        }
        return count;
    }
};