//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow (string s, string t)
    {
        // Your code here
          vector<int> freq(128,0);
        for(int i=0;i<t.size();i++){
            freq[t[i]]++;
        }
        int start=0,end=0,counter=t.size(),minlen=INT_MAX,minstart=0;
        while(end<s.size()){
            char temp=s[end];
            if(freq[temp]>0) counter--;
            freq[temp]--;
            end++;
            while(counter==0){
                if(minlen>end-start){
                    minlen=end-start;
                    minstart=start;
                }
                char chars=s[start];
                freq[chars]++;
                if(freq[chars]>0) counter++;
                start++;
            }
            
        }
        return minlen==INT_MAX? "-1" : s.substr(minstart,minlen);
    }
};

//{ Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        string pat;
        cin>>pat;
        Solution obj;
        cout<<obj.smallestWindow(s, pat)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends