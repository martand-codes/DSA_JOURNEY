/*
------------------------------------------------------------
Problem : Perfect Squares (LeetCode 279)
Pattern : Dynamic Programming (1D / Unbounded Knapsack)

Time Complexity : O(N√N)
Space Complexity : O(N)

Idea:
- dp[i] represents the minimum number of perfect squares
  required to sum to i.
- Initialize all states with n + 1 as infinity because
  the maximum possible answer is n using only 1s.
- For every value i, try every perfect square less than
  or equal to i.
- If square = j², then using it leaves i - square:
      dp[i] = min(dp[i], 1 + dp[i - square])

Key Insight:
Every number can be formed using previously solved
smaller values. Since perfect squares can be reused
unlimited times, each square can be considered multiple
times, making this an unbounded knapsack-style DP.

------------------------------------------------------------
*/

class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, n + 1);
        dp[0] = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j * j <= i; j++) {
                int square = j * j;
                dp[i] = min(dp[i], 1 + dp[i - square]);
            }
        }
        
        return dp[n];
    }
};