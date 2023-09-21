class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        
        int len=tasks.size();
        
        vector<int>freq(26,0);
        
        for(auto itr:tasks)
        {
            freq[itr-'A']++;
        }
        
        //sort in dec order
        
        sort(freq.begin(),freq.end(),greater<int>());
        
        int max_freq=freq[0];
        
        int ideal_places=(max_freq-1)*n;
        
        for(int i=1;i<freq.size();i++)
        {
            ideal_places=ideal_places-min(freq[i],max_freq-1);
        }
        
        //ideal+places can not be negative
        
        return len+max(0,ideal_places);
        
        
    }
};