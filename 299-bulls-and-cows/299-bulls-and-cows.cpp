class Solution
{
    public:
        string getHint(string secret, string guess)
        {

           
            vector<int> arr1(11, 0);
            vector<int> arr2(11, 0);

            int bulls = 0;
            int cows = 0;

            for (int i = 0; i < secret.size(); i++) 
            {
                if(secret[i]==guess[i])
                {
                    bulls++;
                }
                else
                {
                   //heare is the problem
                    arr1[secret[i]-'0']++;
                    arr2[guess[i]-'0']++;
                   
                }
            }
            for(int i=0;i<10;i++)
            {
                cows+=min(arr1[i],arr2[i]);
            }
            string ans=to_string(bulls)+'A'+to_string(cows)+'B';
            
            return ans;
        }
};