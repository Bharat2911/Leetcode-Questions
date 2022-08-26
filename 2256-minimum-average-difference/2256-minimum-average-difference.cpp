class Solution
{
    public:
        int minimumAverageDifference(vector<int> &nums)
        {

            long long n = nums.size();

            if (n == 1)
            {
                return 0;
            }
           	// 
            vector<long long> pre(n);
            vector<long long> suf(n);

            pre[0] = nums[0];
            suf[n - 1] = nums[n - 1];

            for (long long i = 1; i < n; i++)
            {
                pre[i] = pre[i - 1] + nums[i];
            }
             long long sum=pre[n-1];
            
            for (long long i = n - 2; i >= 0; i--)
            {
                suf[i] = suf[i + 1] + nums[i];
            }
           	// cout << endl;
            vector<long long> ans(n);

            for (long long i = 0; i < n-1; i++)
            {
                pre[i] = pre[i] / (i + 1);

                suf[i] = (suf[i+1]) / (n - i-1);
                
               
            }
            pre[n-1]=sum/n;
            suf[n-1]=0;
            
//             for(auto itr:pre)
//             {
//                 cout<<itr<<" ";
//             }
//             cout<<endl;
            
//             for(auto itr:suf)
//             {
//                 cout<<itr<<" ";
//             }
            
//             cout<<endl;
            

         for(long long i=0;i<n;i++)
         {
             ans[i]=abs(pre[i]-suf[i]);
         }
              
            long long idx = 0;
            long long x = ans[0];

            for (long long i = 1; i < n; i++)
            {
                if (ans[i] < x)
                {
                    idx = i;
                    x = ans[i];
                }
            }
            return idx;
        }
};