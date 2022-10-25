class MedianFinder {
public:
    priority_queue<int>pq_max;
    
    priority_queue<int,vector<int>,greater<int>>pq_min;
    
    
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        
        if(pq_max.empty() || num<pq_max.top())
        {
            pq_max.push(num);
        }
        else
        {
            pq_min.push(num);
        }
        //now reshifting step
        if(pq_max.size()>pq_min.size()+1)
        {
            int top=pq_max.top();
            
            pq_max.pop();
            
            pq_min.push(top);
        }
        if(pq_min.size()>pq_max.size()+1)
        {
            int top=pq_min.top();
            
            pq_min.pop();
            
            pq_max.push(top);
        }
    }
    
    double findMedian() {
        
        if(pq_max.size()==pq_min.size())
        {
            return (pq_max.top()+pq_min.top())/2.0;
            
            pq_max.pop();
            
            pq_min.pop();
        }
        else if(pq_max.size()>pq_min.size())
        {
            return pq_max.top();
            
            pq_max.pop();
            
        }
        else
        {
            return pq_min.top();
            
            pq_min.pop();
            
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */