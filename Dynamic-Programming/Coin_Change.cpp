/*
------------------------------------------------------------
Problem : Coin Change (LeetCode 322)
Pattern : Dynamic Programming (Unbounded Knapsack)

Time Complexity : O(N × Amount)
Space Complexity : O(Amount)

Idea:
- dp[j] represents the minimum number of coins required
  to form amount j using the coins processed so far.
- Initialize every state to amount + 1, representing
  an unreachable state.
- dp[0] = 0 because zero coins are required to form 0.
- For each coin, update every amount from coin to amount.
- If the current coin can be used, compare the existing
  minimum with 1 + dp[j - coin].

Key Insight:
Since each coin can be used unlimited times, process
amounts in increasing order. The state dp[j - coin]
may already contain the current coin, allowing it to
be reused.
------------------------------------------------------------
*/



class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // Create our "Fake Infinity"
        int maxVal = amount + 1;
        
        // 1D DP Array, initialized to infinity
        vector<int> dp(amount + 1, maxVal);
        
        // Base case: It takes 0 coins to make an amount of 0.
        dp[0] = 0;
        
        // For every coin we have...
        for (int coin : coins) {
            
            // ...check every amount starting from the coin's value up to the target
            for (int j = coin; j <= amount; j++) {
                
                // DP[j] is the Exclusion (keep whatever minimum we already found)
                // 1 + DP[j - coin] is the Inclusion (use 1 coin + the minimum coins needed for the leftover amount)
                dp[j] = min(dp[j], 1 + dp[j - coin]);
            }
        }
        
        // If the target amount still equals infinity, no combination worked!
        if (dp[amount] == maxVal) {
            return -1;
        }
        
        return dp[amount];
    }
};

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        int maxValue = amount + 1; 
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, maxValue));

        for(int i = 0; i <= n; i++) {
            dp[i][0] = 0;
        }
        for(int i = 1; i <= n; i++) { 
            for(int j = 1; j <= amount; j++) {
                
                if(coins[i - 1] <= j) {
                    dp[i][j] = min(dp[i - 1][j], 1 + dp[i][j - coins[i - 1]]);
                }
                else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        
        if (dp[n][amount] == maxValue) {
            return -1;
        }
        
        return dp[n][amount];
    }
};