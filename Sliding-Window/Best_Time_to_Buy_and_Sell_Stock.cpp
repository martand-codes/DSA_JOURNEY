/*
------------------------------------------------------------
Problem : Best Time to Buy and Sell Stock (LeetCode 121)
Pattern : Greedy + One Pass

Time Complexity : O(N)
Space Complexity : O(1)

Idea:
- Maintain the minimum stock price seen so far.
- For each price, calculate the profit obtained by
  selling at the current price after buying at the
  minimum price.
- Track the maximum profit found.
- Update the minimum price as we traverse the array.

Key Insight:
For every selling day, only the minimum price seen
before that day matters. Therefore, we can find the
maximum profit in a single pass without checking
every possible buy-sell pair.
------------------------------------------------------------
*/


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;
        int min_price = prices[0];
        int max_profit = 0;
        
        for (int i = 1; i < prices.size(); i++) { 
            int current_profit = prices[i] - min_price;
            max_profit = max(max_profit, current_profit);
            min_price = min(min_price, prices[i]);
        } 
        return max_profit;
    }
};