class Solution {
public:
    int solve(int num,int count)
    {
        if(num==0)
        {
            return count;
        }
        if(num%2==0)
        {
            return solve(num/2,count+1);
        }
        else
        {
            return solve(num-1,count+1);
        }
    }
    int numberOfSteps(int num) {
        
        //we will simply use the recursion in this
        return solve(num,0);
    }
};