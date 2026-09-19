/*
------------------------------------------------------------
Problem : Unique Binary Search Trees (LeetCode 96)
Pattern : Dynamic Programming (Catalan Numbers)

Time Complexity : O(N²)
Space Complexity : O(N)

Idea:
- dp[i] represents the number of structurally unique BSTs
  that can be formed using i distinct nodes.
- Consider every node as the root of the BST.
- If j nodes are placed in the left subtree, then
  i - j - 1 nodes are placed in the right subtree.
- The number of BSTs for that root is:
      dp[j] * dp[i - j - 1]
- Sum the possibilities for every possible root.

Key Insight:
The number of unique BSTs with n nodes follows the
Catalan recurrence. Choosing each possible root divides
the remaining nodes into independent left and right
subtree problems.

------------------------------------------------------------
*/

class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n + 1,  0);
        dp[0] = dp[1] = 1;
        if(n == 0) return dp[0];
        for(int i = 2; i<= n; i++) {
            for(int j = 0; j < i; j++) {
                dp[i] += dp[j] * dp[i - j - 1];
            }
        }
        return dp[n];
    }
};