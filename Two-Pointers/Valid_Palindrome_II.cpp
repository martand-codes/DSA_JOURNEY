/*
------------------------------------------------------------
Problem : Valid Palindrome II (LeetCode 680)
Pattern : Two Pointers

Time Complexity : O(N)
Space Complexity : O(1)

Idea:
- Use two pointers to compare characters from both
  ends of the string.
- On the first mismatch, try skipping either the
  left or the right character.
- If either remaining substring is a palindrome,
  return true.

Key Insight:
Only one deletion is allowed, so at the first
mismatch there are exactly two possible choices:
remove the left character or remove the right
character. If neither forms a palindrome, the
answer is false.
------------------------------------------------------------
*/

class Solution {
public:
    
    bool validPalindrome(string s) {
        int start = 0;
        int end = s.size() - 1;
        while(start < end) {
            if(s[start] == s[end]) {
                start++;
                end--;
            } else {
                // Taking case for both start and end pointers
                bool startHelper = helperPalindrome(s, start + 1, end);
                bool endHelper = helperPalindrome(s, start, end - 1);
                return startHelper || endHelper;
            }

        }
        return true;
    }
    bool helperPalindrome(string& s, int left, int right) {
        while(left < right) {
            if(s[left] != s[right]) {
                return false; 
            }
            left++;
            right--;
        }
        return true;
    }
};