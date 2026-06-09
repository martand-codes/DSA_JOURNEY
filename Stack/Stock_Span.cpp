// Problem: Online Stock Span
// Pattern: Monotonic Stack
// TC: O(1) Amortized per query
// SC: O(n)


/*

// Classic Stock Span

void stockSpan(vector<int>& stock, vector<int>& span) {

    stack<int> s;

    s.push(0);
    span[0] = 1;

    for(int i = 1; i < stock.size(); i++) {

        int currentPrice = stock[i];

        while(!s.empty() && stock[s.top()] <= currentPrice) {
            s.pop();
        }

        if(s.empty()) {
            span[i] = i + 1;
        }
        else {
            span[i] = i - s.top();
        }

        s.push(i);
    }
}

*/

class StockSpanner {
    // We use a pair to store {price, span}
    stack<pair<int, int>> st;
    
public:
    StockSpanner() {
        // Stack is initially empty
    }
    
    int next(int price) {
        int span = 1;
        
        // While stack is not empty AND top price is <= today's price
        while (!st.empty() && st.top().first <= price) {
            // Pop the smaller/equal day and absorb its span!
            span += st.top().second;
            st.pop();
        }
        
        // Push today's data onto the stack
        st.push({price, span});
        
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */