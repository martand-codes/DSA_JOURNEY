// Problem: Minimum Cost of Buying Candies With Discount
// Pattern: Greedy + Sorting
// TC: O(n log n)
// SC: O(1)

class Solution {
public:
    int minimumCost(vector<int>& cost) {
        // Sort costs in descending order using reverse iterators
        sort(cost.rbegin(), cost.rend());
        
        int total_cost = 0;
        
        for (int i = 0; i < cost.size(); ++i) {
            // Add to total unless it is the 3rd candy in a group
            if ((i + 1) % 3 != 0) {
                total_cost += cost[i];
            }
        }
        
        return total_cost;
    }
};