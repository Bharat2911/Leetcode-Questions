class Solution {
public:
    string reverseWords(string s) {
        
        stringstream in(s);
        stack<string>st;
        string ans="";
        string temp;
        while(in){
            temp="";
            in>>temp;
            st.push(temp);
        }
        while(!st.empty()){
            auto top=st.top();
            st.pop();
               ans+=top;
               ans+=" ";
            if(st.empty()){
             ans.pop_back();
            }
        }
            ans.erase(0,1);
            return ans;
    }
};