class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        
        string str1="";
        string str2="";
        
        for(auto itr:word1)
        {
            str1+=itr;
        }
        for(auto itr:word2)
        {
            str2+=itr;
        }
        
        if(str1==str2)
        {
            return true;
        }
        return false;

    }
};