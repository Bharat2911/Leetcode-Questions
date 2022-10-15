class Solution
{
    public:
        int compress(vector<char> &chars)
        {

            int n = chars.size();

            string ans = "";

            int count=1;
            
           for(int i=0;i<n-1;i++)
           {
               if(chars[i]==chars[i+1])
               {
                   count++;
               }
               else if(chars[i]!=chars[i+1])
               {
                   if(count>1)
                   {
                       ans=ans+chars[i];
                       ans=ans+to_string(count);
                       
                       count=1;
                   }
                   else
                   {
                       ans=ans+chars[i];
                       
                       count=1;
                   }
                   
                   
               }
           }
            //if reach the end phir se answer me daalo 
            if(count>1)
            {
                ans=ans+chars[n-1];
                ans=ans+to_string(count);
            }
            else
            {
                ans=ans+chars[n-1];
            }
            
            cout<<ans;
            
            for(int i=0;i<ans.size();i++)
            {
                chars[i]=ans[i];
            }
            
            return ans.length();
        }
};