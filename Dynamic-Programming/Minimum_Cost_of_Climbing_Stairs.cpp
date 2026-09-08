
/*
------------------------------------------------------------
Problem : Min Cost Climbing Stairs (LeetCode 746)
Pattern : Dynamic Programming / Tabulation (Bottom-Up)

Time Complexity : O(N)
Space Complexity : O(N)

Idea:
Let dp[i] represent the minimum cost required to reach
step i. To reach step i, we can come from either i-1 or
i-2, so we choose the cheaper previous state and add
cost[i].

Key Insight:
The top of the staircase is not a costed step. It can be
reached from either of the final two steps, so the answer
is min(dp[n-1], dp[n-2]).
------------------------------------------------------------
*/

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();

        vector<int> dp(n);

        dp[0] = cost[0];
        dp[1] = cost[1];

        for (int i = 2; i < n; i++) {
            dp[i] = cost[i] + min(dp[i - 1], dp[i - 2]);
        }

        return min(dp[n - 1], dp[n - 2]);
    }
};