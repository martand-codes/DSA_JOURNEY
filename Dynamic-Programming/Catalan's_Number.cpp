/*
------------------------------------------------------------
Problem : Catalan Number
Pattern : Dynamic Programming (1D / Interval Splitting DP)

Time Complexity : O(N²)
Space Complexity : O(N)

Idea:
- dp[i] represents the i-th Catalan number.
- For every i, consider all possible ways to split i
  into two parts.
- Combine the number of possibilities from both parts:
      dp[i] += dp[j] * dp[i - j - 1]
- Initialize dp[0] = 1 and dp[1] = 1.

Key Insight:
The Catalan recurrence considers every possible split of
a structure into a left part and a right part. For each
split, the number of possibilities is the product of the
possibilities of the two independent parts.

------------------------------------------------------------
*/


int Catalan(int n) {
    vector<int> dp(n + 1, 0);
    dp[0] = 1;

    if(n == 0) return dp[0];

    dp[1] = 1;

    for(int i = 2; i <= n; i++) {
        for(int j = 0; j < i; j++) {
            dp[i] += dp[j] * dp[i - j - 1];
        }
    }

    return dp[n];
}