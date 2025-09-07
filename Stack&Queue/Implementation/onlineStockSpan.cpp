class StockSpanner {
public:
    int idx = -1;
    stack<pair<int, int>> st;
    StockSpanner() {
        idx = -1;
    }
    
    int next(int price) {
        idx++;
        while(!st.empty() and st.top().first <= price) st.pop();
        int ans = st.empty() ? (idx + 1) : (idx - st.top().second);
        st.push({price, idx});
        return ans;
    }
};
// Previous greater el