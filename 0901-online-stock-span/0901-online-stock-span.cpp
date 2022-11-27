class StockSpanner {
public:
    stack<pair<int,int>> s;
    int i = 1;
    StockSpanner() {
        
    }
    
    int next(int price) {
        int ans = 1;
        while(!s.empty() && price >= s.top().first) {
            s.pop();
        }
        if(!s.empty()){
            ans = i - s.top().second;
        } else {
            ans = i;
        }
        s.push({price,i});
        i++;
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */