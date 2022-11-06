class Solution {
public:
    string orderlyQueue(string s, int k) {
        
        //for k==1 rotate the string and find the minimum
        
        //for all other case sort the given string
        
          if(k==1)
        {
            int i,n=s.size();
            string ss=s;
            for(i=0;i<n;i++)
            {
                s=s.substr(1,n-1)+s[0];
                ss=min(ss,s);
            }
            return ss;
        }
        sort(s.begin(),s.end());
        return s;
    }
};