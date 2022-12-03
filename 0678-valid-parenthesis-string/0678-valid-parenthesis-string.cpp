class Solution {
public:
    bool checkValidString(string s) {
        
        //using the stack if we do it
        //T.c=O(n)//itrating once in the string
        //S.C=O(n)//using the stack
        stack<int>open;
        
        stack<int>star;
        
        int n=s.length();
        
        //iss step me apan ne open bracket balance kar liya okk man
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(')
            {
                open.push(i);
            }
            else if(s[i]=='*')
            {
                star.push(i);
            }
            else
            {
                if(!open.empty())
                {
                    open.pop();
                }
                else if(!star.empty())
                {
                    star.pop();
                }
                else
                {
                    return false;
                }
            }
        }
        while(!open.empty())
        {
            if(star.empty())
            {
                return false;
            }
            else if(open.top()<star.top())
            {
                open.pop();
                star.pop();
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};