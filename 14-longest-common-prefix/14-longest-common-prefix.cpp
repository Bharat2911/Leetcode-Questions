class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        //good point 
        //agar bahar hi length define kar dung to lentgh to beta same rahegi na par apan strign str to keep on changing haina
       int n=strs.size();
        
        string str=strs[0];
        
        
        
        for(int i=1;i<n;i++)
        {
            string res="";
            
            int j=0;
                
            while(j<str.length() and strs[i][j]==str[j])
            {
                res+=str[j];
                j++;
            }
            str=res;
        }
        
        return str;
    }
};