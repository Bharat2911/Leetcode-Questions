class Solution {
public:
    int maximum69Number (int num) {
        
        string str=to_string(num);
        
        cout<<str;
        
        for(int i=0;i<str.length();i++)
        {
            if(str[i]=='6')
            {
                str[i]='9';
                break;
            }
        }
        
        int ans=stoi(str);
        
        return ans;
    }
};