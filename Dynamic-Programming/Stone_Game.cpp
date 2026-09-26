/*
------------------------------------------------------------
Problem : Stone Game (LeetCode 877)
Pattern : Dynamic Programming (Game / Score Difference DP)

Time Complexity : O(N²)
Space Complexity : O(N²)

Idea:
- dp[i][j] represents the maximum score difference that
  the current player can achieve from the subarray of piles
  ranging from i to j.
- If the current player takes the left pile, the opponent
  gets the advantage represented by dp[i + 1][j]:
      takeLeft = piles[i] - dp[i + 1][j]
- If the current player takes the right pile:
      takeRight = piles[j] - dp[i][j - 1]
- Choose the move that produces the maximum score
  difference.
- For a single pile, the current player takes it directly:
      dp[i][i] = piles[i]

Key Insight:
Instead of tracking both players' scores separately,
track only the score difference between the current player
and the opponent. After making a move, the opponent becomes
the current player, so their optimal advantage is subtracted
from the current player's gain.

------------------------------------------------------------
*/

class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        return true;

    }
};

class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            dp[i][i] = piles[i];
        }
        for (int i = n - 2; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                
                int takeLeft = piles[i] - dp[i + 1][j];
                int takeRight = piles[j] - dp[i][j - 1];
                
                dp[i][j] = max(takeLeft, takeRight);
            }
        }
        return dp[0][n - 1] > 0;
    }
};