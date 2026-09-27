/*
------------------------------------------------------------
Problem : Longest Common Prefix (LeetCode 14)
Pattern : String Manipulation / Prefix Matching

Time Complexity : O(N × L²)
Space Complexity : O(L)

Idea:
- Start with the first string as the current prefix.
- Compare the prefix with every remaining string.
- If the current string does not start with the prefix,
  repeatedly remove the last character from the prefix.
- Continue until the current string starts with the prefix.
- After processing all strings, the remaining prefix is
  the longest common prefix.

Key Insight:
The common prefix can never be longer than the first
string. By progressively shrinking the candidate prefix
whenever a mismatch occurs, we maintain only prefixes
that are valid for all strings processed so far.

------------------------------------------------------------
*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        string prefix = strs[0];
        for (int i = 1; i < strs.size(); i++) {
            while (strs[i].find(prefix) != 0) {
                prefix = prefix.substr(0, prefix.length() - 1);
            }
        }
        
        return prefix;
    }
};