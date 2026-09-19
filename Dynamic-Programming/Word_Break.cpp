/*
------------------------------------------------------------
Problem : Word Break (LeetCode 139)
Pattern : Dynamic Programming (1D String DP)

Time Complexity : O(N × W × L)
Space Complexity : O(N)

Idea:
- dp[i] represents whether the first i characters of
  the string can be segmented into valid dictionary words.
- Start with dp[0] = true because an empty string is
  considered successfully segmented.
- For every position i, check each word in wordDict.
- If the word matches the substring ending at position i
  and the prefix before that word is already breakable,
  mark dp[i] as true.

Key Insight:
A string can be broken at position i if there exists a
dictionary word that matches the suffix ending at i and
the prefix before that word can already be segmented.
Therefore, each valid word extends a previously solvable
DP state.

------------------------------------------------------------
*/

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();

        vector<bool> dp(n + 1, false);

        dp[0] = true;

        for (int i = 1; i <= n; i++) {

            for (string word : wordDict) {
                int len = word.size();

                if (i >= len) {
                    string suffix = s.substr(i - len, len);      
                    if (suffix == word && dp[i - len] == true) {
                        dp[i] = true;
                        break; 
                    }
                }
            }
        }
        return dp[n];
    }
};