class Solution {
public:
    int brokenCalc(int s, int t) {
        
        //start ko target pe lejane se aacha apan target ko start pe laaye
        
        //recurson;
        
        //base case
        
        if(s==t)return 0;
        
        if(s>t)return s-t;
        
        else if(t%2==0)
        {
            return 1+brokenCalc(s,t/2);
        }
        else return 1+brokenCalc(s,t+1);
    }
};