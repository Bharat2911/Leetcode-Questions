class TimeMap
{
    public:
       	//since increasing order me aayenge hamesha to binary search laga do
        unordered_map<string, vector<pair<int, string>>> map;

    TimeMap() {}

    void set(string key, string value, int timestamp)
    {

        map[key].push_back({ timestamp,
            value });
    }

    string get(string key, int timestamp)
    {

       	//             if present then apply binary searching
//         vector<pair<int, string>> v;

//         v = map[key];
       auto &v=map[key];
        
        int low = 0;
        int high = v.size() - 1;
        int idx = -1;
        int target = timestamp;

        while (low <= high)
        {
            int mid = low + (-low + high) / 2;

            if (v[mid].first <= timestamp)
            {
                idx = mid;
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
                
            
        }
        if(idx==-1)return "";
        return v[idx].second;
           
      

    }
};

/**
 *Your TimeMap object will be instantiated and called as such:
 *TimeMap* obj = new TimeMap();
 *obj->set(key,value,timestamp);
 *string param_2 = obj->get(key,timestamp);
 */