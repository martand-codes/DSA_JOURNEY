/*
------------------------------------------------------------
Problem : Longest Substring Without Repeating Characters
          (LeetCode 3)

Pattern : Hashing + Sliding Window + Two Pointers

Time Complexity : O(N)
Space Complexity : O(min(N, K))
                   K = Character Set Size

Idea:
- Use an unordered_map to store each character's most
  recently encountered index.
- Maintain a sliding window using two pointers:
    left  -> Start of the current valid window.
    right -> End of the current valid window.
- Traverse the string using the right pointer.
- If the current character has appeared before and its
  previous index is inside the current window:
      Move left to the previous index + 1.
- Update the character's latest index in the hash map.
- Calculate the current window length and update max_len.

Key Insight:
The sliding window must always contain unique characters.

The hash map allows us to jump directly past a repeated
character instead of moving the left pointer one position
at a time.

The crucial condition is:

    char_map[c] >= left

It ensures that the previous occurrence belongs to the
CURRENT window. An occurrence outside the window must
not affect the left pointer.

Window Length:

    right - left + 1

Each character is processed once, giving O(N) time.

------------------------------------------------------------
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> char_map;
        int left = 0;
        int max_len = 0;
        
        for (int right = 0; right < s.length(); ++right) {
            char c = s[right];
            
            // If the character is in the map and its last seen index is within the current window
            if (char_map.count(c) && char_map[c] >= left) {
                // Jump the left pointer past the duplicate
                left = char_map[c] + 1;
            }
            
            // Record the current index of the character
            char_map[c] = right;
            
            // Calculate max length
            max_len = max(max_len, right - left + 1);
        }
        
        return max_len;
    }
};