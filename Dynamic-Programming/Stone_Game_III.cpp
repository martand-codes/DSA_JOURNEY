/*
------------------------------------------------------------
Problem : Stone Game III (LeetCode 1406)
Pattern : Dynamic Programming (Game / Score Difference DP)

Time Complexity : O(N)
Space Complexity : O(N)

Idea:
- dp[i] represents the maximum score difference the
  current player can achieve starting from index i.
- At every position, the current player can take 1, 2,
  or 3 stones.
- Calculate the total value of the stones taken.
- After taking those stones, the opponent starts at the
  next position and can achieve dp[i + j + 1].
- Therefore, the current player's net advantage is:
      currentStoneSum - dp[i + j + 1]
- Take the maximum result among all possible choices.
- Finally:
    dp[0] > 0  -> Alice wins
    dp[0] < 0  -> Bob wins
    dp[0] == 0 -> Tie

Key Insight:
Instead of tracking Alice's and Bob's individual scores,
track only the score difference between the current player
and the opponent. Every move flips the perspective, so
subtracting the opponent's optimal score difference gives
the current player's optimal advantage.

------------------------------------------------------------
*/

class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> dp(n + 1, 0); 
        for (int i = n - 1; i >= 0; i--) {
            dp[i] = -1e9;
            int currentStoneSum = 0;
            for (int j = 0; j < 3 && i + j < n; j++) {
                currentStoneSum += stoneValue[i + j];
                dp[i] = max(dp[i], currentStoneSum - dp[i + j + 1]);
            }
        }
        if (dp[0] > 0) return "Alice";
        if (dp[0] < 0) return "Bob";
        return "Tie";
    }
};