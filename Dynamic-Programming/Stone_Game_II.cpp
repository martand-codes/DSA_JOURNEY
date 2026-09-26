/*
------------------------------------------------------------
Problem : Stone Game II (LeetCode 1140)
Pattern : Dynamic Programming (Game DP + Suffix Sum)

Time Complexity : O(N³)
Space Complexity : O(N²)

Idea:
- suffixSum[i] stores the total number of stones remaining
  from index i onward.
- dp[i][M] represents the maximum number of stones the
  current player can collect starting from index i when
  the current maximum allowed value is M.
- The player can take X stones where:
      1 <= X <= 2 * M
- After taking X stones, the opponent starts from i + X
  with a new maximum:
      max(M, X)
- The current player's optimal result is:
      suffixSum[i] - opponent's optimal result
- Try every valid X and take the maximum result.
- If the player can take all remaining stones, the optimal
  result is simply suffixSum[i].

Key Insight:
Instead of tracking both players' scores, calculate how
many stones the opponent can optimally collect from the
remaining suffix. Since the total number of remaining
stones is known through suffixSum, the current player's
score is the total remaining stones minus the opponent's
optimal score.

------------------------------------------------------------
*/


/*

// Memoization
class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<int> suffixSum(n, 0);
        suffixSum[n - 1] = piles[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            suffixSum[i] = suffixSum[i + 1] + piles[i];
        }
        vector<vector<int>> memo(n, vector<int>(n + 1, -1));
        return dfs(0, 1, piles, suffixSum, memo);
    }
    
private:
    int dfs(int i, int M, const vector<int>& piles, const vector<int>& suffixSum, vector<vector<int>>& memo) {
        int n = piles.size();
        if (i >= n) return 0;
        if (i + 2 * M >= n) {
            return suffixSum[i];
        }
        if (memo[i][M] != -1) {
            return memo[i][M];
        }
        
        int maxStones = 0;
        for (int X = 1; X <= 2 * M; X++) {
            int stonesOpponentGets = dfs(i + X, max(M, X), piles, suffixSum, memo);
            int currentStones = suffixSum[i] - stonesOpponentGets;
            
            maxStones = max(maxStones, currentStones);
        }
        
        return memo[i][M] = maxStones;
    }
};

*/

// Tabulation

class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<int> suffixSum(n, 0);
        suffixSum[n - 1] = piles[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            suffixSum[i] = suffixSum[i + 1] + piles[i];
        }
        vector<vector<int>> dp(n, vector<int>(n + 1, 0));
        for (int i = n - 1; i >= 0; i--) {
            for (int M = 1; M <= n; M++) {
                if (i + 2 * M >= n) {
                    dp[i][M] = suffixSum[i];
                } 
                else {
                    int maxStones = 0;
                    for (int X = 1; X <= 2 * M; X++) {
                        int opponentStones = dp[i + X][max(M, X)];
                        int currentStones = suffixSum[i] - opponentStones;
                        
                        maxStones = max(maxStones, currentStones);
                    }
                    
                    dp[i][M] = maxStones;
                }
            }
        }
        return dp[0][1];
    }
};