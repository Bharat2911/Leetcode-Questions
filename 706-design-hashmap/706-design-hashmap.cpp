class MyHashMap {
public:
    vector<pair<bool,int>>map;
    
    MyHashMap() {
        
        map.resize(1e6+1);
        
    }
    
    void put(int key, int value) {
        
        map[key].first=true;
        map[key].second=value;
        
    }
    
    int get(int key) {
        
        //if(present then only return vau)
        if(map[key].first==true)
        {
            return map[key].second;
        }
        return -1;
    }
    
    void remove(int key) {
        
        map[key].first=false;
        
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */