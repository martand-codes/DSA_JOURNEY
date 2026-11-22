/*
------------------------------------------------------------
Problem : Check if All A's Appears Before All B's (LeetCode 2124)
Pattern : String / Substring Search / Built-in String Function

Time Complexity :
O(N) — In the worst case, contains() scans the string to
determine whether the substring "ba" exists.

Space Complexity :
O(1) — No additional data structures are used.

Idea:
1. The string is considered valid if all occurrences of 'a'
   appear before all occurrences of 'b'.
2. The only invalid situation is when a 'b' appears before
   an 'a' somewhere in the string.
3. Such a violation must contain the adjacent substring "ba".
4. Use the built-in contains() function to check whether
   the string contains "ba".
5. Negate the result:
   - If "ba" exists, return false.
   - If "ba" does not exist, return true.

Key Insight:
Instead of checking the positions of every 'a' and 'b',
we only need to detect the invalid adjacent pattern "ba".

Why does checking "ba" work?
If a 'b' occurs before a later 'a', there must be a point
where the sequence transitions from 'b' to 'a'.
That transition creates the substring "ba".

Therefore:

    Valid String <=> "ba" does not exist

C++ Concept:
- string::contains() checks whether a substring exists.
- The ! operator reverses the boolean result.
- The solution directly returns the required condition
  without additional variables or loops.

Complexity Variables:
N = Length of the input string.

------------------------------------------------------------
*/

class Solution {
public:
    bool checkString(string s) {
        return !s.contains("ba");
    }
};