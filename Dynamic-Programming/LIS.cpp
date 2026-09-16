/*
------------------------------------------------------------
Problem : Longest Increasing Subsequence (LIS)
Pattern : Dynamic Programming (LCS Transformation)

Time Complexity : O(N²)
Space Complexity : O(N²)

Idea:
- Remove duplicates from the array and sort the elements.
- The sorted unique array represents the possible
  increasing order of elements.
- Find the Longest Common Subsequence between the original
  array and the sorted unique array.
- The resulting LCS length is the length of the LIS.

Key Insight:
An increasing subsequence of the original array will
appear as a subsequence in its sorted unique version.
Therefore, LIS can be transformed into an LCS problem.

------------------------------------------------------------
*/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        set<int> s(nums.begin(), nums.end());
        vector<int> numsDopelganger(s.begin(), s.end());

        int n = nums.size();
        int m = numsDopelganger.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(nums[i - 1] == numsDopelganger[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[n][m];
    }
};