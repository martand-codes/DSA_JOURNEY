/*
------------------------------------------------------------
Problem : Extra Characters in a String (LeetCode 2707)
Pattern : Dynamic Programming / 1D DP / String Partitioning /
          Hash Set

Time Complexity :
Dictionary Construction : O(D * L)
DP Computation         : O(N^3) Worst Case
Overall                : O(D * L + N^3)

Space Complexity : O(D * L + N)

Idea:
Minimize the number of extra characters left in the
string after partitioning it into dictionary words
and unmatched characters.

Use an unordered_set to store dictionary words for
average O(1) membership checking.

Define:
dp[i] = Minimum number of extra characters in the
        suffix of s starting at index i.

Base Case:
dp[n] = 0
An empty suffix contains no extra characters.

For every index i, initialize:
dp[i] = dp[i + 1] + 1

This represents treating s[i] as an extra character.

Then:
- Iterate over every possible ending index j >= i.
- Extract the substring s[i ... j].
- Check whether the substring exists in the dictionary.
- If it exists, update:
  dp[i] = min(dp[i], dp[j + 1])

This represents using the dictionary word instead
of counting its characters as extra.

Finally, return dp[0].

Key Insight:
Every character can either be treated as an extra
character or included in a dictionary word.

Dynamic programming considers both possibilities
and chooses the minimum number of extra characters.

The suffix-based DP allows optimal decisions for
smaller suffixes to be reused efficiently.

N represents the length of the string.
D represents the number of dictionary words.
L represents the average dictionary word length.

Dictionary construction requires O(D * L) time.

The DP contains O(N^2) substring candidates.
However, constructing each substring using s.substr()
takes O(N) time in the worst case, resulting in
O(N^3) overall DP time.

The DP array requires O(N) space, while the
unordered_set requires O(D * L) space.

------------------------------------------------------------
*/

class Solution {
public:
    int minExtraChar(std::string s, std::vector<std::string>& dictionary) {
        int n = s.length();
        std::unordered_set<std::string> dict(dictionary.begin(), dictionary.end());
        std::vector<int> dp(n + 1, 0);
        for (int i = n - 1; i >= 0; --i) {
            dp[i] = dp[i + 1] + 1;
            for (int j = i; j < n; ++j) {
                std::string sub = s.substr(i, j - i + 1);
                if (dict.count(sub)) {
                    dp[i] = std::min(dp[i], dp[j + 1]);
                }
            }
        }

        return dp[0];
    }
};