/*
------------------------------------------------------------
Problem : Best Time to Buy and Sell Stock with Cooldown
          (LeetCode 309)
Pattern : Dynamic Programming (State Machine DP)

Time Complexity : O(N)
Space Complexity : O(1)

Idea:
- Track three possible states for each day:
    1. hold : Maximum profit while holding a stock.
    2. sold : Maximum profit after selling a stock today.
    3. rest : Maximum profit while not holding a stock
              and not selling today.
- For each day:
    hold = max(previous hold,
               previous rest - current price)
    sold = previous hold + current price
    rest = max(previous rest, previous sold)
- Use the previous day's states to prevent the current
  day's updates from affecting each other.

Key Insight:
After selling a stock, the next day must be a cooldown day.
Therefore, buying is allowed only from the previous `rest`
state. Modeling the problem as a finite set of states makes
the cooldown constraint naturally enforceable.

------------------------------------------------------------
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;
        int hold = -prices[0];
        int sold = 0;
        int rest = 0;

        for (int i = 1; i < prices.size(); i++) {
            int prev_hold = hold;
            int prev_sold = sold;
            int prev_rest = rest;
            hold = max(prev_hold, prev_rest - prices[i]);
            sold = prev_hold + prices[i];
            rest = max(prev_rest, prev_sold);
        }
        return max(sold, rest);
    }
};