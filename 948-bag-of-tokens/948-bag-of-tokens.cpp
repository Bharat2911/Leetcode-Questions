class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        
        
        //this is a simple problem based on greedy
        int n=tokens.size();
        
        if(n==0)return 0;
        
        sort(tokens.begin(),tokens.end());
        
        int i=0;
        int j=n-1;
        int count=0;
        
        //base case
        if(power<tokens[i])return count;
        
        while(i<=j)
        {
            if(tokens[i]<=power)
            {
                power-=tokens[i];
                count+=1;
                
                i++;
            }
            else
            {
                if(count>0 and i!=j)
                {
                    power+=tokens[j];
                    count-=1;
                    
                }
                j--;
            }
        }
        return count;
    }
};