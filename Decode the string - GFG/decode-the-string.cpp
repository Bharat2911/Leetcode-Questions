//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    string decodedString(string s){
        // code here
        
        stack<int>f_st;
        stack<string>ch_st;
        
        int num=0;
        string res="";
        
        
        for(auto itr:s)
        {
            //need to tackel the dour cases
            
            if(isdigit(itr))
            {
                num=num*10+(itr-'0');
                
            }
            else if(isalpha(itr))
            {
                res+=itr;
                
            }
            else if(itr=='[')
            {
                //push in the stack 
                f_st.push(num);
                ch_st.push(res);
                
                //reset the values
                
                num=0;
                res="";
                
            }
            else
            {
                string temp=res;
                res=ch_st.top();
                ch_st.pop();
                
                int freq=f_st.top();
                f_st.pop();
                
               while(freq>0)
               {
                   res+=temp;
                   freq--;
               }
                num=0;
            }
        }
        return res;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        
        Solution ob;
        cout<<ob.decodedString(s)<<"\n";
    }
    return 0;
}
// } Driver Code Ends