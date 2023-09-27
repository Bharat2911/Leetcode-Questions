class Solution {
public:
    string decodeAtIndex(string s, int k) {
       long int size=0;
        int i=0;
        while(size<=k && i<s.length())
        {
            if(isalpha(s[i]))
            {
                size++;
            }
            else{
                size*=(s[i]-'0');
            }
            i++;
        }
    i--;
        while(i>=0)
        {

            k=k%size;
            if(k==0 && isalpha(s[i]))
            {
                return s.substr(i,1);
            }
            if(isalpha(s[i]))
            {
                size--;
            }
            else{
                size/=(s[i]-'0');
            }
            i--;
        }
       
        return "";
    }
};