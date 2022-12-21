class SeatManager {
public:
    map<int,int>map;//store in sorted order
    
    SeatManager(int n) {
        
        for(int i=1;i<=n;i++)
        {
            map[i]=1;
        }
    }
    
    int reserve() {
        
        int ans=0;
        
        for(auto itr:map)
        {
            ans=itr.first;
            break;
        }
        map.erase(ans);//reserve it
        
        return ans;
    }
    
    void unreserve(int n) {
        
        map[n]=1;
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */