// Dp is optimised recursion
// Memoization: Optimizing the recursion

/*
------------------------------------------------------------
Problem : Fibonacci Number (Dynamic Programming)
Pattern : Dynamic Programming / Memoization (Top-Down)

Time Complexity : O(N)
Space Complexity : O(N)

Idea:
Use recursion to calculate Fibonacci numbers and store
already computed results in a DP array.

Key Insight:
Memoization avoids recalculating the same Fibonacci states,
reducing the exponential recursive solution to O(N).
------------------------------------------------------------
*/

int fibDP (int n, vector<int>& dp) {
    if(n == 0 || n == 1) {
        return n;
    } else if ( dp[n] != -1) {
        return dp[n];
    }
    dp[n] = fibDp(n - 1, dp) + fibDp(n - 2, dp);
    return dp[n]; 
} 



/*
------------------------------------------------------------
Problem : Fibonacci Number (Dynamic Programming)
Pattern : Dynamic Programming / Tabulation (Bottom-Up)

Time Complexity : O(N)
Space Complexity : O(N)

Idea:
Build the Fibonacci table iteratively from the base cases.
Each state is computed using the two previously calculated
states.

Key Insight:
Tabulation eliminates recursion by solving smaller subproblems
first and building the answer from the bottom up.
------------------------------------------------------------
*/


int fibTabulation(int n) {
    if (n <= 1) return n;

    vector<int> dp(n + 1);

    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}