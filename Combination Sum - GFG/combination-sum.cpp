// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution {
  public:
    //Function to return a list of indexes denoting the required 
    //combinations whose sum is equal to given number.
    void remove_ele(vector<int>&nums)
    {
        int current=nums[0];
        
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]==current)
            {
                nums.erase(nums.begin()+i);
                i--;
            }
            current=nums[i];
        }
    }
      void solve(int index,vector<int>&nums,int sum,vector<vector<int>>&ans,vector<int>&res)
    {
        //base case
        if(index==nums.size())
        {
            if(sum==0)
            {
                ans.push_back(res);
            }
            return;
        }
        
        //choose and not choose
        if(nums[index]<=sum)
        {
            res.push_back(nums[index]);
            solve(index,nums,sum-nums[index],ans,res);
            
            res.pop_back();//backtraking step
        }
        solve(index+1,nums,sum,ans,res);
    }
    vector<vector<int> > combinationSum(vector<int> &A, int B) {
        // Your code here
        vector<vector<int>>ans;
        vector<int>res;
        sort(A.begin(),A.end());
        remove_ele(A);
        int index=0;
        
        solve(index,A,B,ans,res);
        
        return ans;
    }
};

// { Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            A.push_back(x);
        }   
        int sum;
        cin>>sum;
        Solution ob;
        vector<vector<int>> result = ob.combinationSum(A, sum);
   		if(result.size()==0){
   			cout<<"Empty";
   		}
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}	  // } Driver Code Ends