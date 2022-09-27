class Solution
{
    public:
       	//we will be using the kmp algo here bro jii
        int kmp(string & str)
        {
            int n = str.length();

            if (n < 2) return 0;

            vector<int> lps(n, 0);

            int i = 1;
            int j = 0;

            while (i < n)
            {
                if (str[i] == str[j])
                {
                    lps[i] = j + 1;
                    i++;
                    j++;
                }
                else
                {
                    if (j == 0)
                    {
                        i++;
                    }
                    else
                    {
                        j = lps[j - 1];
                    }
                }
            }
            return lps.back();
        }
    string shortestPalindrome(string str)
    {
        int n = str.length();
        string res = str;
        reverse(res.begin(), res.end());

        string ans = "";

        ans += str + "&" + res;
       	//     ans+=str+res;

        int len = kmp(ans);
        
        //length of longest prefix that is palindrome 
        cout<<len<<endl;
            
        int zx=n-len;
        
        cout<<zx<<endl;
        
        
        string result="";
        
        // reverse(str.begin(),str.end());
        
        int i=0;
        
        while(zx--)
        {
            result+=res[i];
                i++;
        }
        
        return result+str;
    }
};