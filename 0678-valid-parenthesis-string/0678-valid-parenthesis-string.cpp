class Solution {
public:
    bool checkValidString(string s) {
        
        //approach->take two stacks one managing the opena nd close bracket
        //second stack will manage the start
        
        int n=s.length();
        
        stack<int>open;
        stack<int>star;
        
        //positon main hai isme to apan stack me indices ko push kar rhe honge
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
                    open.pop();//balance ho gya close bracket
                }
                else if(!star.empty())
                {
                    star.pop();
                }
                else
                {
                    return false;//dono empty to balance kaise hoga phir
                }
            }
        }
        //balance the open bracket
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