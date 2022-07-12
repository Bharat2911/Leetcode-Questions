class Solution
{
    public:
        bool solve(int index,vector<int>&arr,int curr_sum,int target_sum,vector<int>&vis,int k)
        {
            if(k==0)return true;
            
            if(curr_sum>target_sum)return false;
            
            if(curr_sum==target_sum)
            {
                return solve(0,arr,0,target_sum,vis,k-1);
                
            }
            
            for(int i=index;i<arr.size();i++)
            {
                if(vis[i])continue;
                
                vis[i]=1;
                
                if(solve(i+1,arr,curr_sum+arr[i],target_sum,vis,k))
                {
                    return true;
                }
                
                vis[i]=0;
                
                if(curr_sum==0)break;
            }
            return false;
        }
        bool makesquare(vector<int> &arr)
        {

           	//we just have to check whether we can partition the given subset into four equal sum subset
           	// square properties
           	// all the four sides have equal length 
            
            int k=4;
            
            int n = arr.size();

            int curr_sum = 0;

            int target_sum = 0;

            vector<int> vis(n, 0);

            for (auto itr: arr)
            {
                target_sum += itr;
            }

            if (target_sum % k != 0)
            {
                return false;
                
            }
            if(n<k)return false;
            
            target_sum=target_sum/k;
            
            int index=0;
            
            
            return solve(index,arr,curr_sum,target_sum,vis,k);
            

        }
};