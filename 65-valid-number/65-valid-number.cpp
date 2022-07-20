class Solution
{
    public:
    //only one itration we are doing 
    //T.C=O(n)
    //s.c=O(1)
    
        bool isNumber(string s)
        {

            int n = s.length();
            bool digitseen = false;
            bool dotseen = false;
            bool eseen = false;
            int plusminus=0;
            
            for(int i=0;i<n;i++)
            {
                if(s[i]>='0' and s[i]<='9')
                {
                    digitseen=true;
                }
                else if(s[i]=='+' || s[i]=='-')
                {
                    if(plusminus==2  || i==n-1 ||(i>0 and  s[i-1]!='e' and s[i+1]!='E') )
                    {
                        return false;
                        
                    }
                    
                    plusminus++;
                }
                else if(s[i]=='.')
                {
                    if(eseen || (i==n-1 and !digitseen) || dotseen)//since we cant have more than two dots
                    {
                        return false;
                    }
                    dotseen=true;
                }
                else if(s[i]=='e'  || s[i]=='E')
                {
                    if(eseen || i==n-1 || !digitseen)//we cant have two e and without digit we cant have e 
                    {
                        return false;
                    }
                    eseen=true;
                }
                else
                {
                    return false;
                }
            }
            return true;
        }
};