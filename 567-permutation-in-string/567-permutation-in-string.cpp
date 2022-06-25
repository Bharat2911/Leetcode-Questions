class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        //using the approach of frequency array
        
        int n=s1.length();
        int m=s2.length();
        
        vector<int>for_s1(26,0);
        vector<int>for_s2(26,0);
        
        if(n>m)return false;
        
        int i=0;
        int j=0;
        
        while(j<n)
        {
            for_s1[s1[j]-'a']++;
            for_s2[s2[j]-'a']++;
            j++;
        }
        j-=1;
        
        //now apply sliding window approach
        //n is the window length
        while(j<m)
        {
            
            
            if(for_s1==for_s2)
            {
                return true;
            }
            j++;
            
            if(j!=m)
            {
                //now we have to shrink the window happy
                
                for_s2[s2[i]-'a']--;//decrement freq of prev element
                
                for_s2[s2[j]-'a']++;//increment freq of new element
                
                i++;
            }
        }
        return false;
    }
};