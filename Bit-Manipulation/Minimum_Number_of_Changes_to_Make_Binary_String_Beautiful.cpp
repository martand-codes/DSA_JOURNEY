/*
------------------------------------------------------------
Problem : Minimum Changes To Make Alternating Binary String
          (LeetCode 2914 - Minimum Number of Changes to Make
          Binary String Beautiful)

Pattern : String / Greedy / Pairwise Comparison /
          Single Pass

Time Complexity :
MinChanges : O(N)

Space Complexity : O(1)

Idea:
Find the minimum number of character changes required
to make the binary string beautiful.

A binary string is considered beautiful when it can
be partitioned into substrings of even length, where
each substring contains only identical characters.

- Initialize changes to zero to count the minimum
  number of modifications required.
- Traverse the string in pairs using an increment
  of 2 in the loop.
- Compare the characters at indices i and i + 1.
- If both characters are different:
  - Increment changes because one character must
    be modified to make the pair identical.
- If both characters are already identical:
  - No modification is required.

Finally:
- Return changes as the minimum number of character
  modifications required.

Key Insight:
The string must be divided into consecutive pairs
because every valid substring must have even length.

For each pair:
- If both characters are identical, the pair is
  already beautiful.
- If both characters are different, exactly one
  character must be changed to make them identical.

Each pair can be handled independently, so a greedy
approach is sufficient.

There is no need to modify the actual string or
consider multiple combinations of changes.

N represents the length of the input string.

The loop processes N / 2 pairs, resulting in O(N)
time complexity.

The algorithm uses only the changes counter and
the loop variable, requiring O(1) auxiliary space.

------------------------------------------------------------
*/
class Solution {
public:
    int minChanges(string s) {
        int changes = 0;
        for (int i = 0; i < s.length(); i += 2) {
            if (s[i] != s[i + 1]) {
                changes++;
            }
        }
        return changes;
    }
};