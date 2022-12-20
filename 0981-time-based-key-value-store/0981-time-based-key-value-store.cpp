class TimeMap {
public:
    //we will be using map inside map
    unordered_map<string,map<int,string>>map;
    
    TimeMap() {
        
    }
    
    void set(string key, string value, int time) {
        
        map[key][time]=value;
        
    }
    
    string get(string key, int time) {
        
         auto it=map[key].upper_bound(time);
        if(it==map[key].begin())return "";
        it--;
        return it->second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */