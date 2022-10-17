class Solution {
public:
    bool checkIfPangram(string str) {
        
        
        vector<int>arr(26,0);
        
        for(auto itr:str)
        {
            arr[itr-'a']++;
        }
        
        for(int i=0;i<26;i++)
        {
            if(arr[i]==0)
            {
                return false;
            }
        }
        return true;
    }
};