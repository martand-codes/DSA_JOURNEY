// Problem: For Only Dominoes
// TC: O(2^n)
// Sc: O(n)

class Solution {
public:
    int numTilings(int n) {
        
        // Base Case
        if(n == 0 || n == 1) {
            return 1;
        }

        // For Vertical

        int countVertical = numTilings(n-1);

        // For Horizontal

        int countHorizontal = numTilings(n - 2);

        return countVertical + countHorizontal;
    }
};

// For both Dominoes and Trimonoes Using Recursion
// TC: O(2^n)


class Solution {
public:

    int solve(int n) {

        // Base Cases
        if(n == 0) return 1;
        if(n == 1) return 1;
        if(n == 2) return 2;
        if(n == 3) return 5;

        // Recurrence
        return 2 * solve(n - 1) + solve(n - 3);
    }

    int numTilings(int n) {

        return solve(n);
    }
};

// Using Dynamic Programming

// TC: O(n)
// Sc: O(n)



class Solution {
public:

    int numTilings(int n) {

        const int MOD = 1e9 + 7;

        // Base Cases
        if(n == 1) return 1;
        if(n == 2) return 2;
        if(n == 3) return 5;

        vector<long long> dp(n + 1);

        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 5;

        for(int i = 4; i <= n; i++) {

            dp[i] = (2 * dp[i - 1] + dp[i - 3]) % MOD;
        }

        return dp[n];
    }
};

