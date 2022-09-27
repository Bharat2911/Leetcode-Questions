class Solution {
public:
    string countAndSay(int n) {
        
        //if we want the current answer then i amust know the previous answer
        
        //base case
        
        if(n==1)
        {
            return "1";
        }
        
        string str=countAndSay(n-1);
        
        int count=0;
        
        string res="";//store the element followed by frequency
        
        for(int i=0;i<str.length();i++)
        {
           count++;
            
            if(i==str.length()-1 || str[i]!=str[i+1])
            {
                res+=to_string(count);
                res+=str[i];
                count=0;
            }
           
        }
        return res;
    }
};