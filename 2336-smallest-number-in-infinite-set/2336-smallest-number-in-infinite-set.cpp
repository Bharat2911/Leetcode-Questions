class SmallestInfiniteSet {
public:
    
    priority_queue<int,vector<int>,greater<int>>pq;
    
    unordered_map<int,int>map;
    
 
    
    SmallestInfiniteSet() {
        
        
        for(int i=1;i<=1000;i++)
        {
            pq.push(i);
            map[i]++;
        }
    }
    //min heap ka use karenge idhar mere dost

    
    int popSmallest() {
        
        int top=pq.top();
        
        pq.pop();
        
        map[top]--;
        
        if(map[top]==0)
        {
            map.erase(top);
        }
        
        return top;
    }
    
    //map aur priority queue dono ko saath chalana hai bro jii
    void addBack(int num) {
        
        if(map.find(num)==map.end())//means not present
        {
            pq.push(num);
            map[num]++;
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */