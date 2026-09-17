/*
------------------------------------------------------------
Problem : Decode Ways (LeetCode 91)
Pattern : Dynamic Programming (1D String DP)

Time Complexity : O(N)
Space Complexity : O(N)

Idea:
- dp[i] represents the number of ways to decode the first
  i characters of the string.
- If the current character is not '0', it can be decoded
  individually, so add dp[i - 1].
- Take the last two characters as a number.
- If that number lies between 10 and 26, they can be
  decoded together, so add dp[i - 2].
- Handle an empty string and strings starting with '0'
  as invalid cases.

Key Insight:
At every position, a valid decoding can either use the
current character alone or combine it with the previous
character when the resulting two-digit number is between
10 and 26. The DP state counts all valid ways to reach
the current position.
------------------------------------------------------------
*/


class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n + 1, 0);
        // Base Case
        if(n == 0 || s[0] == '0') {
            return 0;
        }
        dp[0] = 1;
        dp[1] = 1;
        for(int i = 2; i <= n; i++) {
            if(s[i - 1] != '0') {
                dp[i] += dp[i-1];
            }
            int pickTwo = (s[i - 2] - '0') * 10 + (s[i - 1] - '0');

            if(pickTwo >= 10 && pickTwo <= 26) {
                dp[i] += dp[i - 2];
            }
        }
        return dp[n];

        for(int i = 0; i < n; i++) {
            cout<<dp[i]<<endl;
        }
    }
};