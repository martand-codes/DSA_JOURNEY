/*
------------------------------------------------------------
Problem : Merge Strings Alternately (LeetCode 1768)
Pattern : Two Pointers

Time Complexity : O(M + N)
Space Complexity : O(M + N)

Idea:
- Maintain one pointer for each string.
- Alternately append characters from both strings.
- If one string is exhausted, continue appending
  characters from the other string.

Key Insight:
Using two independent pointers naturally handles
strings of different lengths without requiring
separate loops for the remaining characters.
------------------------------------------------------------
*/


class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i = 0;
        int j = 0;
        string result = "";
        while(i < word1.length() || j < word2.length()) {
            if(i < word1.length()) {
                result += word1[i];
                i++;
            }
            if(j < word2.length()) {
                result += word2[j];
                j++;
            }
        }
        return result;
    }
};