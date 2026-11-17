/*
------------------------------------------------------------
Problem : Longest Repeating Character Replacement
          (LeetCode 424)

Pattern : Sliding Window / Two Pointers /
          Frequency Array / Variable-Size Window

Time Complexity :
CharacterReplacement : O(N)

Space Complexity : O(1)

Idea:
Find the length of the longest substring that can be
obtained by replacing at most k characters so that all
characters in the substring become identical.

- Initialize left to zero to represent the starting
  index of the sliding window.
- Initialize maxLength to store the maximum valid
  substring length found so far.
- Initialize maxFrequency to track the highest frequency
  of a single character within the current window.
- Create a frequency array of size 26 to maintain the
  frequency of uppercase English characters.

Sliding Window:
- Traverse the string using right as the ending index
  of the current window.
- Increment the frequency of the current character.
- Update maxFrequency with the highest frequency
  encountered for the current character.
- Calculate the number of replacements required:
  - Window length = right - left + 1.
  - Replacements required = window length - maxFrequency.
- If the replacements required exceed k:
  - Decrement the frequency of the character at left.
  - Move left forward by one position to shrink the
    window.
- Update maxLength using the current window length.

Finally:
- Return maxLength as the length of the longest substring
  that can be converted into a repeating-character
  substring using at most k replacements.

Key Insight:
A substring can be converted into a string containing
identical characters by retaining its most frequent
character and replacing all other characters.

Therefore, the minimum number of replacements required
for a window is:

Window Length - Maximum Character Frequency

If this value exceeds k, the current window is invalid
and its left boundary must be moved forward.

The maxFrequency variable is intentionally not
decreased when the window shrinks.

It stores the historical maximum frequency encountered
during the traversal rather than the exact maximum
frequency of the current window.

This optimization avoids repeatedly calculating the
maximum frequency across all 26 characters.

Although maxFrequency may become stale after shrinking
the window, the algorithm still correctly determines
the maximum achievable window length because the window
is contracted by at most one position per iteration.

N represents the length of the input string.
K represents the maximum number of allowed replacements.

Each character is processed once by the right pointer,
and the left pointer moves forward at most N times.

Each frequency array operation takes O(1) time because
the array contains exactly 26 entries.

Therefore, the overall time complexity is O(N).

The frequency array has a fixed size of 26, requiring
constant auxiliary space, resulting in O(1) space.

------------------------------------------------------------
*/

class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0;
        int maxLength = 0;
        int maxFrequency = 0;
        vector<int> frequency(26, 0);

        for (int right = 0; right < s.size(); right++) {
            frequency[s[right] - 'A']++;
            maxFrequency = max(maxFrequency, frequency[s[right] - 'A']);
            if ((right - left + 1) - maxFrequency > k) {
                frequency[s[left] - 'A']--;
                left++;
            }
            maxLength = max(maxLength, right - left + 1);
        }
        return maxLength;
    }
};