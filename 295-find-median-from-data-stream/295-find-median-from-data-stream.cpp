class MedianFinder {
public:
    //make the min heap as well as max heap itrs important boy
    priority_queue<int>max_pq;//max heap
    
    priority_queue<int,vector<int>,greater<int>>min_pq;//this is min heap
    
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        
        if(max_pq.empty() || num<max_pq.top())
        {
            max_pq.push(num);
        }
        else
        {
            min_pq.push(num);
        }
        
        if(min_pq.size()>max_pq.size()+1)
        {
            max_pq.push(min_pq.top());
            min_pq.pop();
        }
        else if(max_pq.size()>min_pq.size()+1)
        {
            min_pq.push(max_pq.top());
            max_pq.pop();
        }
    }
    
    double findMedian() {
        
        if(max_pq.size() == min_pq.size()){
           return (max_pq.top() + min_pq.top()) / 2.0;
       }
        else{
            if(max_pq.size() > min_pq.size()){
                return max_pq.top();
            }else{
                return min_pq.top();
            }
        }
       
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */