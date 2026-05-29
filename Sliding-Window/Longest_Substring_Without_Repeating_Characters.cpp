// Problem: Longest Substring Without Repeating Characters
// Pattern: Sliding Window + Hashing
// TC: O(n)
// SC: O(min(n, charset))

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