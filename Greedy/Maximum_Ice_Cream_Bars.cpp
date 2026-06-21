// Problem: Maximum Ice Cream Bars
// Pattern: Greedy + Counting Sort
// TC: O(n + M)
// SC: O(M)
//
// Idea:
// 1. Count frequency of each ice cream cost.
// 2. Buy cheapest ice creams first.
// 3. Use counting sort instead of sorting the entire array.
// 4. Greedily maximize the number of bars purchased.

class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int n = costs.size();
        
        
        int max_cost = 0;
        for (int c : costs) max_cost = max(max_cost, c);
        vector<int> counts(max_cost + 1, 0);

        for (int cost : costs) {
            counts[cost]++;
        }
        
        int ice_cream_bars = 0;
        int remaining_coins = coins;
        for (int price = 1; price <= max_cost; ++price) {
            int num_available = counts[price];
            if (num_available == 0) {
                continue;
            }
            if (price > remaining_coins) {
                break;
            }
            int max_can_afford = remaining_coins / price;
            
            int num_to_buy = min(num_available, max_can_afford);
            ice_cream_bars += num_to_buy;
            remaining_coins -= num_to_buy * price;
        }
        
        return ice_cream_bars;
    }
};