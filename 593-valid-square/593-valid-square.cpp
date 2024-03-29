class Solution {
public:
    int distance(vector<int>&p1,vector<int>&p2)
    {
        return (p1[0]-p2[0])*(p1[0]-p2[0]) + (p1[1]-p2[1])*(p1[1]-p2[1]);
        
    }
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        
        //find the distance of each combination then push that in set as we knw set dont contain duplicate elements
        
        set<int>set;
        set.insert(distance(p1,p2));
        set.insert(distance(p1,p3));
        set.insert(distance(p1,p4));
        set.insert(distance(p2,p3));
        set.insert(distance(p2,p4));
        set.insert(distance(p3,p4));
       
        
        if(!set.count(0) and set.size()==2)return true;
        
        return false;
        
        
    }
};