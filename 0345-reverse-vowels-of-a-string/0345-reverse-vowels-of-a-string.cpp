class Solution {
public:
    bool is_vowel(char ch)
    {
        if(ch=='a' || ch=='A' || ch=='e' || ch=='E' || ch=='i' || ch=='I' || ch=='o' || ch=='O' || ch=='u' || ch=='U')
        {
            return true;
        }
        return false;
        
    }
    string reverseVowels(string s) {
        
        int n=s.length();
        
        int i=0;
        int j=n-1;
        
        while(i<j)
        {
            if(!is_vowel(s[i]))
            {
                i++;
            }
            
            if(!is_vowel(s[j]))
            {
                j--;
            }
            
            if(is_vowel(s[i]) and is_vowel(s[j]))
            {
                swap(s[i],s[j]);
                
                i++;
                j--;
            }
        }
        
        return s;
        
    }
};