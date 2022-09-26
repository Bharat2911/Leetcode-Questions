class StockSpanner {
public:
    vector<int>ans;
    
    stack<pair<int,int>>st;
    
    StockSpanner() {
        
    }
    
    int next(int price) {
        
       
        
//         ans.push_back(price);
        
//         int count=0;
        
//         int n=ans.size();
        
//         int x=ans[n-1];
        
//         for(int i=n-1;i>=0;i--)
//         {
//             if(ans[i]<=x)
//             {
//                 count++;
//             }
//             else
//             {
//                 break;
//             }
//         }
//         return count;
        int count=1;
        
        while(!st.empty() and st.top().first<=price)
        {
            count+=st.top().second;
            st.pop();
        }
        st.push({price,count});
        return count;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */