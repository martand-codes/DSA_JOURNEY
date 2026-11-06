/*
------------------------------------------------------------
Problem : Valid Palindrome (LeetCode 125)
Pattern : Two Pointers

Time Complexity : O(N)
Space Complexity : O(1)

Idea:
Use two pointers starting from opposite ends of the string.
Skip non-alphanumeric characters and compare remaining
characters after converting them to lowercase.

Key Insight:
A palindrome reads the same forwards and backwards.
By comparing characters from both ends and moving inward,
we can validate it in a single traversal without creating
an additional filtered string.
------------------------------------------------------------
*/

class Solution {
public:
    bool isPalindrome(string s) {
        int start = 0;
        int end = s.length() - 1;

        while (start < end) {
            if (!isalnum(s[start])) {
                start++;
            } 
            else if (!isalnum(s[end])) {
                end--;
            } 
            else {
                if (tolower(s[start]) != tolower(s[end])) {
                    return false; 
                }
                start++;
                end--;
            }
        }
        
        return true; 
    }
};