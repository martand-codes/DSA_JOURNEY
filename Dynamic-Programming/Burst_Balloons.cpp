/*
------------------------------------------------------------
Problem : Burst Balloons (LeetCode 312)
Pattern : Dynamic Programming + Interval DP

Time Complexity : O(N^3)
Space Complexity : O(N^2)

Idea:
- Add 1 to both ends of the array to create virtual
  boundaries.
- Create a 2D DP table where dp[i][j] represents the
  maximum coins obtainable by bursting all balloons
  strictly between indices i and j.
- Process intervals in increasing order of their gap.
- For every interval [i, j], try each balloon k between
  i and j as the LAST balloon to burst.
- Calculate the coins earned from bursting k last:
      modified_nums[i] * modified_nums[k] * modified_nums[j]
- Add the optimal results from the left and right intervals:
      dp[i][k] + dp[k][j]
- Store the maximum total in dp[i][j].
- Return dp[0][n - 1].

Key Insight:
Think about the LAST balloon burst, not the first.

If balloon k is burst last within the interval (i, j),
all balloons between i and k, and between k and j, have
already been removed.

Therefore, the adjacent balloons when k is burst are
the fixed boundaries i and j.

Recurrence:

    dp[i][j] = max(
        dp[i][k] + dp[k][j]
        + modified_nums[i] * modified_nums[k] * modified_nums[j]
    )

The interval DP works because choosing the last balloon
separates the problem into two independent subproblems.

------------------------------------------------------------
*/
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size() + 2; // For Setting Boundaries
        vector<vector<int>> dp(n, vector<int>(n, 0));
        vector<int> modified_nums(n, 1);
        
        for (int i = 0; i < nums.size(); i++) {
            modified_nums[i + 1] = nums[i]; 
        }
        // Gap is the space between boundaries
        for (int gap = 2; gap < n; gap++) {
            for (int i = 0; i < n - gap; i++) {
                int j = i + gap; // Right boundary
                for (int k = i + 1; k < j; k++) {
                    int coins_at_k = modified_nums[i] * modified_nums[k] * modified_nums[j];
                     int total_coins = dp[i][k] + dp[k][j] + coins_at_k;
                     dp[i][j] = max(dp[i][j], total_coins);
                }
            }
        }
        return dp[0][n - 1];
    }
};