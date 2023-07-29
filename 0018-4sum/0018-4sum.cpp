class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& arr, int k) {
        
         vector<vector<int> >v;
        sort(arr.begin(), arr.end());
        if(arr.size()<4)return{};
        for(int i = 0; i < arr.size()-3; i++)
        {
            for(int j = i+1; j < arr.size()-2; j++)
            {
                int l = j+1;
                int r = arr.size()-1;
                while(l < r)
                {
                    vector<int>v1;
                    if((long long )arr[i]+arr[j]+arr[l]+arr[r] == k)
                    {
                        v1.push_back(arr[i]);
                        v1.push_back(arr[j]);
                        v1.push_back(arr[l]);
                        v1.push_back(arr[r]);
                        
                        v.push_back(v1);
                        l++;
                        r--;
                    }
                    else if((long long )arr[i]+arr[j]+arr[l]+arr[r] < k)
                        l++;
                    else
                        r--;
                    
                }
            }
        }
        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());
        return v;
    
    }
};