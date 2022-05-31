class Solution {
public:
    //store the substring of size k in the set and then just check whether number od distinct sunstring of size k ==2^k
    bool hasAllCodes(string s, int k) {
        
        int n=s.length();
        
        unordered_set<string>set;
        
        for(int i=0;i<n-k+1;i++)
        {
            set.insert(s.substr(i,k));
        }
        
        
        if(set.size()==pow(2,k))return true;
        return false;
        
    }
};