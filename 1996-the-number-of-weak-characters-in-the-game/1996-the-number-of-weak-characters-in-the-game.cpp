class Solution {
public:
    static bool comp(vector<int>&a,vector<int>&b)
    {
        if(a[0]==b[0])return a[1]>b[1];
        
        return a[0]<b[0];
    }
    int numberOfWeakCharacters(vector<vector<int>>& arr) {
        
        //its just sorting and observation my friend
        
        sort(arr.begin(),arr.end(),comp);
        
        int n=arr.size();
        
        int count=0;
        
        int mini=INT_MIN;
        
        for(int i=n-1;i>=0;i--)
        {
            if(arr[i][1]<mini)
            {
                count++;
            }
            else
            {
                mini=arr[i][1];
            }
        }
        return count;
    }
};