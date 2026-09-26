class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int totalSum = 0;
        for (int num : nums) {
            totalSum += num;
        }
        if (abs(target) > totalSum || (totalSum + target) % 2 != 0) {
            return 0;
        }
        int subsetTarget = (totalSum + target) / 2;
        vector<int> dp(subsetTarget + 1, 0);
        dp[0] = 1;
        for (int num : nums) {
            for (int j = subsetTarget; j >= num; j--) {
                dp[j] += dp[j - num];
                
            }
        }
        
        return dp[subsetTarget];
    }
};