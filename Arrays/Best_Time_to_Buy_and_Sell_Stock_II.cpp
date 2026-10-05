/*
------------------------------------------------------------
Problem : Best Time to Buy and Sell Stock II (LeetCode 122)
Pattern : Greedy

Time Complexity : O(N)
Space Complexity : O(1)

Idea:
- Traverse the prices from left to right.
- Whenever today's price is greater than yesterday's,
  take the profit from that increase.
- Add every positive price difference to the total profit.

Key Insight:
Any increasing sequence can be split into individual
profitable transactions without reducing the total profit.

For example:

    1 → 3 → 5

Instead of one transaction:
    Buy at 1, Sell at 5 = 4

we can take:
    1 → 3 = 2
    3 → 5 = 2

Total = 4

Therefore, every positive consecutive difference can
be safely added to the answer.

------------------------------------------------------------
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0;
        for (size_t i = 1; i < prices.size(); ++i) {
            if (prices[i] > prices[i - 1]) {
                max_profit += prices[i] - prices[i - 1];
            }
        }
        return max_profit;
    }
};