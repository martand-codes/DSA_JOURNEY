/*
------------------------------------------------------------
Problem : Combination Sum IV (LeetCode 377)
Pattern : Dynamic Programming (1D / Unbounded Knapsack)

Time Complexity : O(N × Target)
Space Complexity : O(Target)

Idea:
- dp[i] represents the number of combinations that can
  form the sum i.
- Initialize dp[0] = 1 because there is exactly one way
  to form sum 0: choose nothing.
- For every target value i, try every number in nums.
- If num <= i, every way to form i - num can be extended
  by adding num:
      dp[i] += dp[i - num]

Key Insight:
Order matters in this problem. Therefore, the target sum
is the outer loop and nums is the inner loop. This counts
different sequences separately, such as 1 + 2 and 2 + 1.

------------------------------------------------------------
*/

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<unsigned int>dp(target + 1, 0);
        dp[0] = 1;

        for(int i = 1; i <= target; i++) {
            for(int num : nums) {
                if(i >= num) {
                    dp[i] += dp[i - num];
                }
            }
        }
        return dp[target];
    }
};