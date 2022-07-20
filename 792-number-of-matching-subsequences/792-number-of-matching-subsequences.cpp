class Solution {
public:

    bool issubsequence(string s,string &t)
    {
        //check s is subsequence of t or not
       int i=0;
       int j=0;
        
        int n=s.length();
        int m=t.length();
        
        while(i<n and j<m)
        {
            if(s[i]==t[j])
            {
                i++;
                j++;
            }
            else
            {
                j++;
            }
        }
        if(i==n)
        {
            return true;
        }
        return false;
        
        
    }
    int numMatchingSubseq(string s, vector<string>& words) {
        
        //find the longest common subsequence here
        int count=0;
        unordered_map<string ,int>map;//so that we dont pick the repeating char again and gin
        
        
        for(int i=0;i<words.size();i++)
        {
            map[words[i]]++;
        }
        
        for (auto itr:map)
        {
            string p=itr.first;
            
            if(issubsequence(p,s) )
            {
                count+=itr.second;
            }
        }
        return count;
    }
};