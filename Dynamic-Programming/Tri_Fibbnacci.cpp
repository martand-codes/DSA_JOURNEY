/*
------------------------------------------------------------
Problem : N-th Tribonacci Number (LeetCode 1137)
Pattern : Dynamic Programming / Tabulation (Bottom-Up)

Time Complexity : O(N)
Space Complexity : O(N)

Idea:
Build the Tribonacci sequence iteratively from the base
cases. Each state is computed using the previous three
Tribonacci values.

Key Insight:
Unlike Fibonacci, where each state depends on two previous
states, Tribonacci depends on the previous three states.
------------------------------------------------------------
*/

class Solution {
public:
    int tribonacci(int n) {
        if(n <= 1) {
            return n;
        }
        vector<int> dp(n + 1);
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 1;

        for(int i = 3; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
        }
        return dp[n];
    }
};