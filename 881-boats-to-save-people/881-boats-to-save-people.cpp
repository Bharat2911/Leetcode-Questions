class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        
        //if i think greefly then i will carry one heavy weight person and ont light weight person
        //T.C=O( n log n)
        //S.C=O(1)
        
        int n=people.size();
        
        sort(people.begin(),people.end());
        
        int i=0;
        int j=n-1;
        
        int count=0;
        
        while(i<=j)
        {
             if(people[i]+people[j]<=limit)
             {
                 count++;//use one boat that wil;l carry onelight and one heavy weight person
                 
                 i++;
                 
                 j--;
             }
            else
            {
                count++;//use boat that only carry one heavy weight persom
                
                j--;
            }
        }
        return count;
    }
};