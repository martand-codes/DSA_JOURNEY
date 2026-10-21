/*
------------------------------------------------------------
Problem : Minimum Operations to Make String Sorted
Pattern : Greedy + Character Extremes

Time Complexity : O(N)
Space Complexity : O(1)

Idea:
- Check whether the string is already sorted in
  non-decreasing order. If so, return 0.
- If the string has length 2 and is not sorted,
  return -1 because it cannot be sorted using the
  allowed operation.
- Find the smallest and largest characters in the string.
- If the first character is the smallest or the last
  character is the largest, return 1.
- Otherwise, if the smallest or largest character appears
  somewhere in the interior, return 2.
- If none of these conditions hold, return 3.

Key Insight:
The minimum number of operations depends on where the
smallest and largest characters are positioned.

    Already sorted             → 0 operations
    Smallest at start OR
    largest at end             → 1 operation
    Smallest or largest
    in the interior            → 2 operations
    Otherwise                  → 3 operations

For a string of length 2, an unsorted string cannot be
sorted using the allowed operation, so return -1.

------------------------------------------------------------
*/

class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        bool sorted = true;
        for(int i = 1; i < n; i++) {
            if(s[i] < s[i - 1]) {
                sorted = false;
                break;
            }
        }
        if(sorted) {
            return 0;
        }
        if(n == 2) {
            return -1;
        }
        char small = *min_element(s.begin(), s.end());
        char big = *max_element(s.begin(), s.end());

        if(s[0] == small || s[n - 1] == big){
           return 1;
        }
        for(int  i = 1; i < n - 1; i++) {
            if(s[i] == small || s[i] == big) {
                return 2;
            }
        }
        return 3;
    }
};