class StockSpanner {
    stack<pair<int,int>> st; // {price, span}
public:
    StockSpanner() {}

    int next(int price) {
        int span = 1;
        // Pop all smaller/equal prices and add their spans
        while(!st.empty() && st.top().first <= price) {
            span += st.top().second;
            st.pop();
        }
        st.push({price, span});
        return span;
    }
};
