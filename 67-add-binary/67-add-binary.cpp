class Solution
{
    public:
        string addBinary(string a, string b)
        {

           	//sincew sum hamesha peeche se hota hia 
            int n = a.length();
            int m = b.length();

            int i = n - 1;
            int j = m - 1;

            string ans = "";

            int carry = 0;

            while (i >= 0 || j >= 0)
            {
                int sum = 0;

                if (i >= 0) sum += a[i] - '0';	//convert to askii value
                if (j >= 0) sum += b[j] - '0';

                i--;
                j--;

                sum += carry;
                if (sum > 1) carry = 1;
                else carry = 0;

                ans += to_string(sum % 2);
            }
            if (carry == 1)
            {
                ans += to_string(carry);
            }
            reverse(ans.begin(),ans.end());
            return ans;
        }
};