class Solution {
public:
    //concept is that 
    
    //if we want A=B*C then B<A and C<A(that why we sort it )
    //and A%B==0 and C=A/B (we use map to check whether we got c or not in our given array)
    
    long long mod=1e9+7;
    
    int numFactoredBinaryTrees(vector<int>& arr) {
        
        //we have to sort it first
        
        
        sort(arr.begin(),arr.end());
        
        unordered_map<int,long long int>map;
        
        int n=arr.size();
        
        //note we dont have the duplicates in the given array
        
        for(auto itr:arr)
        {
            map[itr]++;
        }
        
        for(int i=1;i<n;i++)
        {
            long long int count=0;
            
            for(int j=0;j<i;j++)
            {
                if(arr[i]%arr[j]==0)//we got the one leaf node
                {
                    if(map.find(arr[i]/arr[j])!=map.end())//we have the second leaf node here
                    {           
                        //my one leaf node is ->arr[j];
                        
                        //and other leaf node is -> arr[i]/arr[j];
                        
                        count+=map[arr[j]]*map[arr[i]/arr[j]];
                        
                    }
                }
            }
            map[arr[i]]+=count;
        }
        long long int sum=0;
        for(auto itr:map)
        {
            sum=(sum+itr.second)%mod;
        }
        return sum%mod;
    }
};