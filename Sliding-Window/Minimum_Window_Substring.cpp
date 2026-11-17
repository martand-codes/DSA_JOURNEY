/*
------------------------------------------------------------
Problem : Minimum Window Substring (LeetCode 76)

Pattern : Sliding Window / Two Pointers /
          Variable-Size Window / Hash Map /
          Frequency Counting

Time Complexity :
MinWindow : O(N + M)

Space Complexity : O(1)

Idea:
Find the smallest substring in s that contains all
characters of t, including their required frequencies.

- If the length of s is smaller than the length of t,
  immediately return an empty string because a valid
  window cannot exist.
- Initialize an unordered_map charCount to store the
  required frequency of every character in t.
- Traverse t and increment the frequency of each
  character in charCount.
- Initialize targetCharsRemaining to t.length() to
  track the number of required characters that have
  not yet been matched.
- Initialize minWindow to store the starting and ending
  indices of the smallest valid window.
- Initialize startIndex to zero as the left boundary
  of the sliding window.

Expanding the Window:
- Traverse s using endIndex as the right boundary.
- Retrieve the current character ch.
- If ch exists in charCount and its remaining required
  frequency is greater than zero:
  - Decrement targetCharsRemaining because a required
    character has been matched.
- Decrement charCount[ch] to account for the character
  entering the current window.
- Once targetCharsRemaining becomes zero, all required
  characters of t are present in the current window.

Contracting the Window:
- While the current window remains valid:
  - Retrieve the character at startIndex.
  - If the character belongs to t and its frequency
    in charCount is exactly zero:
    - Stop shrinking because removing it would make
      the window invalid.
  - Otherwise:
    - Increment its frequency in charCount.
    - Move startIndex forward.
- Compare the current valid window length with the
  previously recorded minimum window length.
- If the current window is smaller:
  - Update the starting index in minWindow.
  - Update the ending index in minWindow.
- Remove the character at startIndex from the valid
  window by incrementing its frequency.
- Increment targetCharsRemaining because one required
  character is no longer covered.
- Move startIndex forward to continue searching
  for another valid window.

Finally:
- If minWindow was never updated, return an empty string.
- Otherwise, extract and return the smallest valid
  substring using s.substr().

Key Insight:
The algorithm maintains the required character
frequencies using a hash map and dynamically adjusts
a variable-size sliding window.

targetCharsRemaining tracks the total number of
required character occurrences that are still missing,
rather than simply counting distinct characters.

This handles duplicate characters correctly.

For example, if t contains two occurrences of 'A',
both occurrences must be present in the window before
targetCharsRemaining reaches zero.

The frequency map also tracks surplus characters:
- Positive frequency means more occurrences are needed.
- Zero frequency means the required count is satisfied.
- Negative frequency means the window contains
  extra occurrences of that character.

Once all required characters are present, the left
pointer moves forward to remove unnecessary characters
and minimize the window.

After recording the smallest valid window, one required
character is deliberately removed to make the window
invalid again, allowing the right pointer to search
for the next valid window.

Each character is processed at most a constant number
of times by the two sliding window pointers.

N represents the length of string s.
M represents the length of string t.

Building the frequency map requires O(M) time.

The right pointer traverses s at most N times, and
the left pointer also moves forward at most N times.

Therefore, the overall time complexity is O(N + M)
on average, assuming average O(1) hash map operations.

The hash map stores at most the number of distinct
characters encountered in s and t.

For a fixed character set, the auxiliary space is O(1).

For a general character set, the auxiliary space
is O(N + M) in the worst case.

------------------------------------------------------------
*/

class Solution {
public:
    string minWindow(string s, string t) {
        if (s.length() < t.length()) {
            return "";
        }

        unordered_map<char, int> charCount;
        for (char ch : t) {
            charCount[ch]++;
        }

        int targetCharsRemaining = t.length();
        int minWindow[2] = {0, INT_MAX};
        int startIndex = 0;

        for (int endIndex = 0; endIndex < s.length(); endIndex++) {
            char ch = s[endIndex];
            if (charCount.find(ch) != charCount.end() && charCount[ch] > 0) {
                targetCharsRemaining--;
            }
            charCount[ch]--;

            if (targetCharsRemaining == 0) {
                while (true) {
                    char charAtStart = s[startIndex];
                    if (charCount.find(charAtStart) != charCount.end() && charCount[charAtStart] == 0) {
                        break;
                    }
                    charCount[charAtStart]++;
                    startIndex++;
                }

                if (endIndex - startIndex < minWindow[1] - minWindow[0]) {
                    minWindow[0] = startIndex;
                    minWindow[1] = endIndex;
                }

                charCount[s[startIndex]]++;
                targetCharsRemaining++;
                startIndex++;
            }
        }

        return minWindow[1] >= s.length() ? "" : s.substr(minWindow[0], minWindow[1] - minWindow[0] + 1);        
    }
};