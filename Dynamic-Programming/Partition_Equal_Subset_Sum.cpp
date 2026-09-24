/*
------------------------------------------------------------
Problem : Partition Equal Subset Sum (LeetCode 416)
Pattern : Dynamic Programming (0/1 Knapsack / Subset Sum)

Time Complexity : O(N × Target)
Space Complexity : O(N × Target)

Idea:
- Calculate the total sum of all elements.
- If the total sum is odd, equal partitioning is
  impossible.
- Otherwise, the problem becomes finding whether a subset
  exists whose sum is exactly totalSum / 2.
- dp[i][j] represents whether a sum of j can be formed
  using the first i elements.
- For every element, either:
    1. Do not include it:
       dp[i - 1][j]
    2. Include it:
       dp[i - 1][j - nums[i - 1]]
- If either choice is possible, dp[i][j] is true.

Key Insight:
Equal partition is possible exactly when a subset can
produce half of the total sum. This transforms the problem
into the classic 0/1 subset-sum problem, where every number
can be used at most once.

------------------------------------------------------------
*/

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int totalSum = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            totalSum += nums[i];
        }
        if (totalSum % 2 != 0) {
            return false;
        }
        int target = totalSum / 2;
        vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));
        for (int i = 0; i <= n; i++) {
            dp[i][0] = true;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= target; j++) {
                
                if (nums[i - 1] <= j) {
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i - 1]];
                } 
                else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        
        return dp[n][target];
    }
};