class StockSpanner {
   stack<pair<int,int>>st;
public:

    StockSpanner() {
        
    }
    
    int next(int price) {
          
           int collect=0;
           while(!st.empty()&&st.top().first<=price)
           {
                collect+=st.top().second;
                st.pop();
           }
           st.push({price,collect+1});
           return st.top().second;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */