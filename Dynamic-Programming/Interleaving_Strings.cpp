/*
------------------------------------------------------------
Problem : Interleaving String (LeetCode 97)
Pattern : Dynamic Programming (2D → 1D String DP)

Time Complexity : O(M × N)
Space Complexity : O(N)

Idea:
- dp[j] represents whether the first i characters of s1
  and the first j characters of s2 can form the first
  i + j characters of s3.
- At every position, the next character of s3 must come
  from either s1 or s2.
- If the character comes from s1, use the previous row:
      dp[j]
- If the character comes from s2, use the current row's
  previous column:
      dp[j - 1]
- Combine both possibilities using OR.
- Compress the original 2D DP table into a single array.

Key Insight:
At position i + j in s3, only two choices are possible:
take the next character from s1 or take it from s2.
The 1D optimization works because each state only depends
on the previous row's same column and the current row's
previous column.

------------------------------------------------------------
*/

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.size();
        int n = s2.size();
        if (m + n != s3.size()) {
            return false;
        }
        vector<bool> dp(n + 1, false);
        
        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                int k = i + j - 1; 
                if (i == 0 && j == 0) {
                    dp[j] = true;
                } 
                else if (i == 0) {
                    dp[j] = dp[j - 1] && (s2[j - 1] == s3[k]);
                } 
                else if (j == 0) {
                    dp[j] = dp[j] && (s1[i - 1] == s3[k]);
                } 
                else {
                    bool takeDown = dp[j] && (s1[i - 1] == s3[k]);
                    bool takeRight = dp[j - 1] && (s2[j - 1] == s3[k]);
                    
                    dp[j] = takeDown || takeRight;
                }
            }
        }
        return dp[n];
    }
};