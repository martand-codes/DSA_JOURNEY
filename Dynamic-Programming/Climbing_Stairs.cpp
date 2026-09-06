/*
------------------------------------------------------------
Problem : Climbing Stairs (LeetCode 70)
Pattern : Dynamic Programming / Tabulation (Bottom-Up)

Time Complexity : O(N)
Space Complexity : O(N)

Idea:
Let dp[i] represent the number of distinct ways to reach
step i. To reach step i, we can come from either i-1 or i-2.

Key Insight:
The number of ways to reach the current step is the sum of
the ways to reach the previous two steps.
------------------------------------------------------------
*/

class Solution {
public:
    int climbStairs(int n) {
        // Base Case
        if(n == 0 || n == 1) {
            return 1;
        }
        vector<int> dp(n + 1, 0);
        // Seeding the Vector
        dp[0] = 1; 
        dp[1] = 1;
         
        
        for(int i = 2; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
            
        }
        return dp[n];
    }
};