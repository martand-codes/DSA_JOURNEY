/*
------------------------------------------------------------
Problem : Candy (LeetCode 135)
Pattern : Greedy + Two Passes

Time Complexity : O(N)
Space Complexity : O(N)

Idea:
- Initially give every child 1 candy.
- First pass from left to right:
    - If ratings[i] > ratings[i - 1], child i must receive
      more candies than the child on the left.
- Second pass from right to left:
    - If ratings[i] > ratings[i + 1], child i must receive
      more candies than the child on the right.
    - Use max() to preserve the requirement established
      by the first pass.
- Finally, sum all candy counts.

Key Insight:
The two passes handle the two independent constraints:

    Left neighbor  → increasing ratings
    Right neighbor → decreasing ratings

A single pass cannot reliably satisfy both directions.
The second pass uses:

    max(candies[i], candies[i + 1] + 1)

so that fixing the right-side requirement never breaks
the requirement already established from the left.

------------------------------------------------------------
*/

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> candies(n, 1);

        for (int i = 1; i < n; ++i) {
            if (ratings[i] > ratings[i - 1]) {
                candies[i] = candies[i - 1] + 1;
            }
        }

        for (int i = n - 2; i >= 0; --i) {
            if (ratings[i] > ratings[i + 1]) {
                candies[i] = max(candies[i], candies[i + 1] + 1);
            }
        }

        int total = 0;
        for (int c : candies) {
            total += c;
        }

        return total;
    }
};