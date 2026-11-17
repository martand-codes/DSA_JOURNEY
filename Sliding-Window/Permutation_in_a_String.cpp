/*
------------------------------------------------------------
Problem : Permutation in String (LeetCode 567)

Pattern : Sliding Window / Fixed-Size Window /
          Frequency Array / String Matching

Time Complexity :
CheckInclusion : O(N + M)

Space Complexity : O(1)

Idea:
Determine whether s2 contains a contiguous substring
whose characters form a permutation of s1.

- Calculate the lengths of both strings:
  - N1 represents the length of s1.
  - N2 represents the length of s2.
- If s2 is shorter than s1, immediately return false
  because a substring of the required length cannot exist.
- Initialize two frequency arrays of size 26:
  - c1 stores the frequency of characters in s1.
  - c2 stores the frequency of characters in the
    current sliding window of s2.

First Window Initialization:
- Traverse the first n1 characters of both strings.
- Increment the corresponding character frequencies
  in c1 and c2.
- Compare both frequency arrays.
- If they are equal, return true because the first
  window is a permutation of s1.

Sliding Window:
- Start traversing s2 from index n1.
- For every new character entering the window:
  - Increment its frequency in c2.
- Remove the character leaving the window:
  - Decrement the frequency of s2[i - n1] in c2.
- Compare c1 and c2 after every window shift.
- If both frequency arrays are equal, return true
  because the current window contains exactly the same
  character frequencies as s1.

Finally:
- If no matching frequency window is found, return false.

Key Insight:
Two strings are permutations of each other if and only
if they contain exactly the same characters with
identical frequencies.

Therefore, instead of generating every possible
permutation of s1, the algorithm compares character
frequency arrays.

A fixed-size sliding window of length n1 ensures that
every candidate substring in s2 has the same length
as s1.

When the window moves one position forward, only two
frequency updates are required:
- Add the incoming character.
- Remove the outgoing character.

This avoids recalculating character frequencies for
every substring.

The frequency arrays contain exactly 26 entries,
representing lowercase English letters.

N represents the length of s1.
M represents the length of s2.

Building the initial frequency arrays takes O(N) time.

The sliding window processes the remaining M - N
characters, performing constant-time frequency updates
for each position.

Comparing two fixed-size arrays of 26 elements takes
O(26) = O(1) time per window.

Therefore, the overall time complexity is O(N + M).

Both frequency arrays have a fixed size of 26,
requiring constant auxiliary space, resulting in O(1)
space complexity.

------------------------------------------------------------
*/

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.size(), n2 = s2.size();
        if (n2 < n1) return false;

        vector<int> c1(26, 0), c2(26, 0);

        for (int i = 0; i < n1; i++) {
            c1[s1[i] - 'a']++;
            c2[s2[i] - 'a']++;
        }

        if (c1 == c2) return true;

        for (int i = n1; i < n2; i++) {
            c2[s2[i] - 'a']++;
            c2[s2[i - n1] - 'a']--;

            if (c1 == c2) return true;
        }

        return false;
    }
};