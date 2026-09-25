/*
------------------------------------------------------------
Problem : Last Stone Weight II (LeetCode 1049)
Pattern : Dynamic Programming (0/1 Knapsack / Subset Sum)

Time Complexity : O(N × Target)
Space Complexity : O(Target)

Idea:
- The final stone weight can be viewed as the difference
  between two groups of stones.
- To minimize this difference, divide the stones into two
  groups whose sums are as close as possible.
- Let totalSum be the sum of all stones and target be
  totalSum / 2.
- Use 0/1 subset-sum DP to find the largest achievable
  subset sum j that is less than or equal to target.
- The other group's sum is totalSum - j.
- Therefore, the final difference is:
      totalSum - 2 * j

Key Insight:
The original stone-smashing process can be transformed
into a partition problem. Finding the subset closest to
half of the total sum produces the minimum possible
remaining stone weight.

------------------------------------------------------------
*/

class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int totalSum = 0;
        for (int stone : stones) {
            totalSum += stone;
        }   
        int target = totalSum / 2;
        vector<bool> dp(target + 1, false);
        dp[0] = true;
        for (int stone : stones) {
            for (int j = target; j >= stone; j--) {
                if (dp[j - stone] == true) {
                    dp[j] = true;
                }
            }
        }
        for (int j = target; j >= 0; j--) {
            if (dp[j] == true) {
                return totalSum - (2 * j);
            }
        }
        
        return 0;
    }
};