class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        
         if(trust.size()==0 && n==1) return 1;
        else if(trust.size()==0 && n!=1) return -1;

        unordered_map<int, int> hash_map;
        vector<int> vec(n, 0);
        for(auto trst: trust){
            hash_map[trst[0]]++;
            vec[trst[1]-1]++;
        }
        
        int ans=-1;
        for(int i=0; i<n; i++){
            if(vec[i]==n-1 && hash_map.count(i+1)==0){
                ans = i+1;
                break;
            }
        }
        return ans;
    }
};