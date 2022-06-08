// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct petrolPump
{
    int petrol;
    int distance;
};


 // } Driver Code Ends
/*
The structure of petrolPump is 
struct petrolPump
{
    int petrol;
    int distance;
};*/

/*You are required to complete this method*/
class Solution{
  public:
  
    //Function to find starting point where the truck can start to get through
    //the complete circle without exhausting its petrol in between.
    int tour(petrolPump p[],int n)
    {
       //Your code here
       int  ans=0;
       int ef=0;//extra fuel we have
       int rf=0;//required fuel ,,fuel we need
       
       for(int i=0;i<n;i++)
       {
           ef+=p[i].petrol-p[i].distance;
           
           if(ef<0)
           {
               ans=i+1;
               rf+=ef;
               ef=0;
           }
       }
       if(rf+ef>=0)
       {
           return ans;
       }
       else
       {
           return -1;
       }
    }
};



// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        petrolPump p[n];
        for(int i=0;i<n;i++)
            cin>>p[i].petrol>>p[i].distance;
        Solution obj;
        cout<<obj.tour(p,n)<<endl;
    }
}
  // } Driver Code Ends