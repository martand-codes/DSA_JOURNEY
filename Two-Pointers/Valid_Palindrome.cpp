/*
------------------------------------------------------------
Problem : Valid Palindrome (LeetCode 125)
Pattern : Two Pointers

Time Complexity : O(N)
Space Complexity : O(1)

Idea:
- Place one pointer at the beginning and another at
  the end of the string.
- Skip all non-alphanumeric characters.
- Compare the remaining characters after converting
  them to lowercase.
- If all corresponding characters match, the string
  is a valid palindrome.

Key Insight:
Instead of constructing a filtered string, process
the original string in-place by skipping unwanted
characters using two pointers.
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

