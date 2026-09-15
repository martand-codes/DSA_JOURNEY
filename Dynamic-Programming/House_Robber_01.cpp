/*
------------------------------------------------------------
Problem : House Robber (LeetCode 198)
Pattern : Dynamic Programming / Tabulation (Bottom-Up)

Time Complexity : O(N)
Space Complexity : O(N)

Idea:
Let dp[i] represent the maximum money that can be robbed
from houses 0 through i.

For every house, choose between:
1. Excluding the current house: dp[i - 1]
2. Robbing the current house: dp[i - 2] + nums[i]

Key Insight:
Adjacent houses cannot both be robbed, so every state is
the maximum of skipping the current house or robbing it
while using the best result from two houses back.
------------------------------------------------------------
*/

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        if (n == 1)
            return nums[0];

        vector<int> dp(n);

        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for (int i = 2; i < n; i++) {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }

        return dp[n - 1];
    }
};