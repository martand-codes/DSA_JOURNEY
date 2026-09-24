class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n + 1, 0);
        dp[1] = 0;
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j < i; j++) {               
                int keepWhole = j * (i - j);
                int breakFurther = j * dp[i - j];
                dp[i] = max({dp[i], keepWhole, breakFurther});
            }
        }       
        return dp[n];
    }
};