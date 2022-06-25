// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:

	    void solve(int index,vector<string>&ans,string &str)
	    {
	        //base case
	        if(index==str.length())
	        {
	            ans.push_back(str);
	            return;
	        }
	        for(int i=index;i<str.length();i++)
	        {
	            //apply filter condition sice we dont need duplicates
	            if(i!=index and str[i-1]==str[i])
	            {
	                continue;
	            }
	            swap(str[index],str[i]);
	            
	            solve(index+1,ans,str);
	            
	            swap(str[index],str[i]);
	        }
	    }
		vector<string>find_permutation(string S)
		{
		    // Code here there
		    vector<string>ans;
		    
		    int index=0;
		    sort(S.begin(),S.end());
		    solve(index,ans,S);
		    sort(ans.begin(),ans.end());
		    
		    return ans;
		}
};



// { Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}
  // } Driver Code Ends