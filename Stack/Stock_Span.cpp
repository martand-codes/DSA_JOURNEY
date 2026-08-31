/*
------------------------------------------------------------
Problem : Online Stock Span (LeetCode 901)
Pattern : Monotonic Stack

Time Complexity :
- next() : O(1) amortized

Space Complexity : O(N)

Idea:
- Use a monotonic decreasing stack.
- Each stack element stores:
      {price, span}

- The span represents how many consecutive previous days
  have a stock price less than or equal to the current
  day's price.

For every new price:
    1. Start with span = 1 because today's day is always
       included.
    2. While the stack is not empty and the previous price
       is <= today's price:
          - Absorb its entire span.
          - Pop it from the stack.
    3. Push today's {price, span}.
    4. Return the calculated span.

Example:

Prices:
    100, 80, 60, 70, 60, 75

Process:

    100
    Stack:
        {100, 1}

    80
    80 < 100
    Stack:
        {100, 1}
        {80, 1}

    60
    60 < 80
    Stack:
        {100, 1}
        {80, 1}
        {60, 1}

    70
    70 > 60
    Pop {60, 1}

    span = 1 + 1 = 2

    Stack:
        {100, 1}
        {80, 1}
        {70, 2}

    60
    60 < 70

    Stack:
        {100, 1}
        {80, 1}
        {70, 2}
        {60, 1}

    75
    75 > 60
    Pop {60, 1}

    span = 1 + 1 = 2

    75 > 70
    Pop {70, 2}

    span = 2 + 2 = 4

    75 < 80
    Stop.

    Push {75, 4}

The span of 75 is 4.

Key Insight:
Instead of storing every individual previous day, store
the span that each price has already accumulated.

When a price is popped, its entire span can be absorbed
in O(1):

    span += st.top().second;

This effectively skips over multiple previous days at once.

Why the while loop is still O(N) amortized:
- Every price is pushed exactly once.
- Every price is popped at most once.

Therefore, across all calls:

    Total work = O(N)

The stack maintains prices in decreasing order.

------------------------------------------------------------
*/


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