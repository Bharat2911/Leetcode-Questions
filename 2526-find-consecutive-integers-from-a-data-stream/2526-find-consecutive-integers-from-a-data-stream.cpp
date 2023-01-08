class DataStream {
public:
    int len=0;
    int val=0;
    int count=0;
    
    DataStream(int value, int k) {
        
        len=k;
        val=value;
    }
    
    bool consec(int num) {
        
        if(num==val)
        {
            count++;
        }
        else
        {
            count=0;
        }
        
        if(count>=len)return true;
        return false;
    }
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */