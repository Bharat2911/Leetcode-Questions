class Solution {
public:
    int numRescueBoats(vector<int>& arr, int lim) {
        
        int n=arr.size();
        
        sort(arr.begin(),arr.end());
        
        int i=0;
        int j=n-1;
        int count=0;
        
        while(i<=j)
        {
            
            if(arr[i]+arr[j]>lim)
            {
                //send the heaviest person
                count++;
                j--;
            }
            else
            {
                // /send both persom
                count++;
                i++;
                j--;
            }
        }
        return count;
    }
};