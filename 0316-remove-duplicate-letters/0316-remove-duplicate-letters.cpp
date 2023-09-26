class Solution {
public:
    string removeDuplicateLetters(string s) {
        
         vector<bool>vis(26,0);//true if element present in stack
        vector<int>count(26,0);//stroe the total instances of that character
        
        stack<int>st;//stirng the ans
        string ans;
        
        for(auto i:s)
        {
            count[i-'a']++;
        }
        
        for(auto itr:s)
        {
            int curr_char=itr-'a';
            
            count[curr_char]--;
            
            if(!vis[curr_char])
            {
                vis[curr_char]=true;
                
                while(!st.empty() and count[st.top()] and curr_char<st.top())
                {
                    //stack se nikal dunga aur uska visitef false kar dunga
                    vis[st.top()]=false;
                    st.pop();
                }
                st.push(curr_char);
            }
        }
        
       while(!st.empty()) {
            ans = string(1, 'a'+st.top()) + ans;
            st.pop();
        }
        return ans;
    }
};