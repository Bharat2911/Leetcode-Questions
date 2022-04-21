class Solution
{
    public:
        int numSplits(string s)
        {

            int n = s.length();

            vector<int> prefix(n);
            vector<int> suffix(n);

            set<char> pre;
            set<char> suff;

           	//fillinh the prefix araay

            for (int i = 0; i < n; i++)
            {
                pre.insert(s[i]);
                
                prefix[i] = pre.size();
                
                 
            }
            
            //fillinf the suffix array
            
            for (int i = 0; i <n; i++)
            {
                suff.insert(s[n-1-i]);
                suffix[n-1-i] = suff.size();
            }
            
            int count=0;
            
            for(int i=0;i<n-1;i++)
            {
                if(prefix[i]==suffix[i+1])
                {
                    count++;
                }
            }
            return count;
        }
};