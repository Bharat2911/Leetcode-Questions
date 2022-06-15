class Solution
{
    public:
    static bool comp(string &s1 ,string &s2)
    {
        return s1.size()<s2.size();
    }
        bool compare(string &s1, string &s2)
        {
            int n = s1.length();
            int m = s2.length();
            //str1 is greater and str2 is smaller  since in subsequence manner 
            
            if(n!=m+1)return false;
            
            int count = 0;

            int ptr1 = 0;
            int ptr2 = 0;

            while (ptr1 < n )
            {
                if (s1[ptr1] == s2[ptr2])
                {
                    ptr1++;
                    ptr2++;
                }
                else if (s1[ptr1] != s2[ptr2])
                {
                    ptr1++;
                    count++;
                }
            }
            if (count == 1) return true;
            return false;
        }
    int longestStrChain(vector<string> &words)
    {

       	//prerequsite is lis in this problem 
       	//a basic dp problem one must knw how to do it

       	//same as lis ,in lis we search for increasing subsequnce but here we will search for the subsequence which differ only with one character
        
        
        int n = words.size();
        vector<int> dp(n, 1);
         
        //we have to sort acc to the length 
        sort(words.begin(),words.end(),comp);
        
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (compare(words[i], words[j]) and dp[i] < dp[j] + 1)
                {
                    dp[i] = dp[j] + 1;
                }
            }
        }
        int maxi = INT_MIN;

        for (int i = 0; i < n; i++)
        {
            maxi = max(maxi, dp[i]);
        }
        return maxi;
    }
};