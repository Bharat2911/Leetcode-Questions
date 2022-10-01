class Solution {
public:
    int numDecodings(string s) {
          int size = s.size();
        vector<int> M; //length n+2 "array"
        M.push_back(0); //prevent out of bounds error
        M.push_back(1); //prevent out of bounds error
        M.push_back(s[0]!='0'); //size 1 base case
        
        int res = 0;
        for(int i = 2; i<=size; i++){
            res = 0;
            //if last digit is not 0 -> can look at first n-1 nums
            if(s[i-1]!='0')
                res += M[i];

            //if last two characters form a number 10-26 -> can look at first n-2 nums
            if(s[i-2] == '1' ||  s[i-2] == '2' && s[i-1] < '7' )
                res += M[i-1];
            
            M.push_back(res);
        }
        
        return M[size+1];
    }
};