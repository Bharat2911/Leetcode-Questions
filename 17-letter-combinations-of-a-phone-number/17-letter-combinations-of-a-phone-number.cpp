class Solution {
public:
   void fun(string digits,vector<string> str,vector<string> &ans,int n,int i,string temp)
{
    if(i>n)
        return ;
    if(i==n)
    {
        ans.push_back(temp);
        return ;
    }
    for(char s : str[(digits[i]-'0')])
        fun(digits,str,ans,n,i+1,temp+s);
}
vector<string> letterCombinations(string digits) 
{
    if(digits == "")
        return {};
    vector<string> str,ans;
    str={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    int n=digits.size();
    fun(digits,str,ans,n,0,"");
    return ans;
}
};