class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
//         vector<int>freq(26,0);
        
//         for(auto itr:letters)
//         {
//             freq[itr-'a']++;
//         }
//         vector<char>ans(1);
        
//         for(int i=0;i<26;i++)
//         {
//             int x=target-'a';
            
//             if(freq[i]>0 and i>x)
//             {
//                 ans[0]= i+'a';
//                 break;
//             }
//         }
//        //tackle the wrap around case
        
//         return ans[0];
        int t=target - '0';
        
        for(char x:letters){
            
            int y=x-'0';
            if(y>t)return x;
        }
        
        return letters[0];
    }
};