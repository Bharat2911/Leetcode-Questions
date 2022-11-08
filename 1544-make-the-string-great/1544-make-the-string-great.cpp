class Solution {
public:
   
    string makeGood(string s) {
        
        // int n=s.length();/
        
        //we will be using the stack here
        
         stack<char>st;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(st.empty()){
                st.push(s[i]);
            }
            else if(abs(st.top()-s[i])==32){
                st.pop();
             }
            else st.push(s[i]);
        }
        string s1;
        int sz=st.size();
        for(int i=0;i<sz;i++){
            s1.push_back(st.top());
            st.pop();
        }
        reverse(s1.begin(),s1.end());
        return s1;
    }
};