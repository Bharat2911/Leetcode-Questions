class Solution {
public:
    int maxScore(vector<int>& A, int B) {
        
        //store the sum of first k elemnts 
        //then delet element from last from sum and elemnt from last
       int n=A.size();
    int sum=0;
    int res=0;

    for(int i=0;i<B;i++ )
    {
        res+=A[i];
    }
    sum=res;


    for(int i=0;i<B;i++)
    {
       sum-=A[B-1-i];
       sum+=A[n-1-i];

       res=max(res,sum);
    }
    return res;
    }
};