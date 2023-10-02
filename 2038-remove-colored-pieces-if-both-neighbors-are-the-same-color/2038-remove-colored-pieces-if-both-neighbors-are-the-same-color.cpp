class Solution {
public:
    bool winnerOfGame(string colors) {
        
        int counta=0;
        
        int countb=0;
        
        
        int a=0;
        
        int b=0;
        
        int n=colors.length();
        
        for(int i=0;i<n;i++)
        {
            if(colors[i]=='A')
            {
                counta++;
            }
            else
            {
                if(counta>=3)
                {
                    a+=counta-2;
                }
                
                counta=0;
            }
        }
        if(counta>=3)
        {
            a+=counta-2;
            
        }
        
        for(int i=0;i<n;i++)
        {
            if(colors[i]=='B')
            {
                countb++;
            }
            else
            {
                if(countb>=3)
                {
                    b+=countb-2;
                    
                }
                countb=0;
            }
        }
        if(countb>=3)
        {
            b+=countb-2;
        }
        
        if(a>b)return true;
        
        else return false;
    }
};