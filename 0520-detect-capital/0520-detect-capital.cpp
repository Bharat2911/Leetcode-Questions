class Solution {
public:
    bool detectCapitalUse(string word) {
        
        int n=word.length();
        
        int c1=0;//for capital
        int c2=0;//for small
        
        for(auto itr:word)
        {
            if(itr>='A' and itr<='Z')
            {
                c1++;
                
            }
            else
            {
                c2++;
            }
        }
        //case when  all capital
        if(c1>0 and c2==0)
        {
            return true;
        }
        //case when all small
        else if(c2>0 and c1==0)
        {
            return true;
        }
        else if(c1==1  and (word[0]>='A' and word[0]<='Z') )
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};