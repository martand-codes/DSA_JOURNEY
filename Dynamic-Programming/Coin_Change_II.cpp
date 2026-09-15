/*
------------------------------------------------------------
Problem : Coin Change II (LeetCode 518)
Pattern : Dynamic Programming (Unbounded Knapsack)

Time Complexity : O(N × Amount)
Space Complexity : O(Amount)

Idea:
- dp[j] represents the number of combinations that
  can form amount j using the coins processed so far.
- Initialize dp[0] = 1 because there is exactly one
  way to form amount 0: choose no coins.
- For every coin, update amounts from coin to amount.
- dp[j - coin] represents ways to form the remaining
  amount after including the current coin.

Key Insight:
Process coins in the outer loop and amounts in increasing
order. This ensures each combination is counted exactly
once regardless of the order in which its coins appear.
------------------------------------------------------------
*/


class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        // Changed the type to prevent overflow crash
        vector<vector<unsigned int>> dp(n + 1, vector<unsigned int>(amount + 1, 0));
        
        for(int i = 0; i < n + 1; i++) {
            dp[i][0] = 1;
        }
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= amount; j++) {
                if(coins[i - 1] <= j) {
                    // Inclusion -> Inclusion + Exclusion (As we want no of ways)
                    dp[i][j] = dp[i][j - coins[i - 1]] + dp[i - 1][j];
                }
                else{
                    // Exclusion
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[n][amount];
    }
};


class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<unsigned int> dp(amount + 1, 0);
        dp[0] = 1; 
        for (int coin : coins) { 
            for (int j = coin; j <= amount; j++) {

                // dp[j] excluding the coin 
                // dp[j - coin] including the coin
                dp[j] = dp[j] + dp[j - coin];
            }
        }
        
        return dp[amount];
    }
};