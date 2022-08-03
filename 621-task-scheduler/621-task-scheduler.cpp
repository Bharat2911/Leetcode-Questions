class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        
        //similar laga mujhe reorganized string ke 
        
        int len=tasks.size();
        
        //make the freq array and sort it to get the max frequency
        vector<int>freq(26,0);
        
        for(auto itr:tasks)
        {
            freq[itr-'A']++;//since we have been given elements in upper case
            
        }
        
        sort(freq.begin(),freq.end(),greater<int>());//sort in decreasing order
        
        int max_freq=freq[0];
        
        int ideal_places=(max_freq-1)*n;
        
        
        for(int i=1;i<freq.size();i++)
        {
            ideal_places=ideal_places-min(max_freq-1,freq[i]);
        }
        //since we dont want out ideal place to be negavtive
        
        return len+max(0,ideal_places);
        
    }
};