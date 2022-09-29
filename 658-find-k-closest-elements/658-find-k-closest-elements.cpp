class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        
        //will solving this using pq
        
        //since if dist is same we will be picking the min element so sort the array so that every time min is picked
        sort(arr.begin(),arr.end());
        
        priority_queue<pair<int,int>>pq;//max heap ->{dist,elemnt}
        
        vector<int>ans;
        
        for(int i=0;i<arr.size();i++)
        {
            pq.push({abs(arr[i]-x),arr[i]});
            
            if(pq.size()>k)
            {
                pq.pop();
            }
        }
        for(int i=0;i<k;i++)
        {
            int top=pq.top().second;
            pq.pop();
            
            ans.push_back(top);
        }
        sort(ans.begin(),ans.end());
        
        return ans;
    }
};