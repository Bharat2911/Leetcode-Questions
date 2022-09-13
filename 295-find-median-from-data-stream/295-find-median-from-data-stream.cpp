class MedianFinder
{
    public:
       	//make two heaps min heap and max heap
        priority_queue<int> pmax;
    priority_queue<int, vector < int>, greater < int>> pmin;

    MedianFinder() {}

    void addNum(int num) 
    {
        if(pmax.empty() || num<pmax.top())
        {
            pmax.push(num);
        }
        else
        {
            pmin.push(num);
        }
        
        if(pmax.size()>pmin.size()+1)
        {
            int x=pmax.top();
            pmax.pop();
            
            pmin.push(x);
        }
        else if(pmin.size()>pmax.size()+1)
            
        {
            int y=pmin.top();
            pmin.pop();
            
            pmax.push(y);
        }
            
            
        
    }

    double findMedian()
    {

        if (pmax.size() == pmin.size())
        {
            return (pmax.top() + pmin.top()) / 2.0;
        }
        else if (pmax.size() > pmin.size())
        {
            return pmax.top();
        }
        else 
        {
            return pmin.top();
        }
    }
};

/**
 *Your MedianFinder object will be instantiated and called as such:
 *MedianFinder* obj = new MedianFinder();
 *obj->addNum(num);
 *double param_2 = obj->findMedian();
 */