class Solution {
public:
    string getHint(string secret, string guess) {
        
        //bulls+A+cows+B
        int bulls=0;
        int cows=0;
        
        vector<int>for_s(10,0);
        vector<int>for_p(10,0);
        
        for(int i=0;i<secret.length();i++)
        {
            if(secret[i]==guess[i])
            {
                bulls++;//digits which are at the corect posiitions
                
            }
            else
            {
                for_s[secret[i]-'0']++;
                for_p[guess[i]-'0']++;
            }
        }
        for(int i=0;i<10;i++)
        {
            cows+=min(for_s[i],for_p[i]);
        }
        return to_string(bulls)+"A"+to_string(cows)+"B";
    }
};