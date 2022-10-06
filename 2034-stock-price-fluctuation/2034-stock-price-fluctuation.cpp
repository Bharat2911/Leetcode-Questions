class StockPrice {
public:
    //this will give tle
    
    unordered_map<int,int>map;
    int curr;
    
    //we will optimised it using the max heap and min heap to get max and min 
    priority_queue<pair<int,int>>pq_max;//max heap
    
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq_min;//min heap
    
    
    StockPrice() {
        
    }
    
    void update(int timestamp, int price) {
        
        map[timestamp]=price;
        curr=max(curr,timestamp);
        
        pq_max.push({price,timestamp});
         pq_min.push({price,timestamp});
        
    }
    
    int current() {
        
      return map[curr];
    }
    
    int maximum() {
        
//         int maxi=0;
//         int x=0;
        
//         for(auto itr:map)
//         {
//             if(itr.second>maxi)
//             {
//                 maxi=itr.second;
//             }
//         }
//         return maxi;
        
        while(!pq_max.empty() and pq_max.top().first!=map[pq_max.top().second])
        {
            pq_max.pop();
        }
      return  pq_max.top().first;
        
    }
    
    int minimum() {
//         int mini=INT_MAX;
//         int x=0;
        
//         for(auto itr:map)
//         {
//             if(itr.second<mini)
//             {
//                 mini=itr.second;
//             }
//         }
//         return mini;
         while(!pq_min.empty() and pq_min.top().first!=map[pq_min.top().second])
        {
            pq_min.pop();
        }
       return  pq_min.top().first;
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */