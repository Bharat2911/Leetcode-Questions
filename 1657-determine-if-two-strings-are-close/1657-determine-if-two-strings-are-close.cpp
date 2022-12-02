class Solution {
public:
    bool closeStrings(string word1, string word2) {
        
        int l1=word1.length();
        int l2=word2.length();
        
        //base case
        if(l1!=l2)
        {
            return false;
        }
        
        unordered_map<char,int>map1;
        unordered_map<char,int>map2;
        
        string s1="";
        string s2="";
        
        
        vector<int>v1;
        vector<int>v2;
        
        for(auto itr:word1)
        {
            map1[itr]++;
        }
        
        for(auto itr:word2)
        {
            map2[itr]++;
        }
        
        for(auto itr:map1)
        {
            v1.push_back(itr.second);
            s1+=itr.first;
        }
        for(auto itr:map2)
        {
            v2.push_back(itr.second);
            s2+=itr.first;
        }
        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end());
        sort(s1.begin(),s1.end());
        sort(s2.begin(),s2.end());
        
        
        if(v1==v2 and s1==s2)
        {
            return true;
        }
        return false;
    
    }
};