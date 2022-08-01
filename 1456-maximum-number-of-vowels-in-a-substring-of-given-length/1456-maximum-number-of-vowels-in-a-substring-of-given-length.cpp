class Solution {
public:
    int maxVowels(string s, int k) {
        
        int n=s.length();
        
        int i=0;
        int j=0;
        
        int vowels=0;
        
        int ans=0;
        
        while(j<n)
        {
            if(s[j]=='a' || s[j]=='e' || s[j]=='i' || s[j]=='o' || s[j]=='u')
            {
                vowels++;
            }
            
            if(j-i+1<k)
            {
                j++;
            }
            else if(j-i+1==k)
            {
                ans=max(ans,vowels);
                
                if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u')
                {
                    vowels--;
                }
                
                i++;
                j++;
            }
        }
        return ans;
    }
};