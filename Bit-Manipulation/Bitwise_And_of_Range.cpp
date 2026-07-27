/*
------------------------------------------------------------
Problem : Bitwise AND of Numbers Range (LeetCode 201)
Pattern : Bit Manipulation

Time Complexity : O(1)
Space Complexity : O(1)

Idea:
- Right shift both left and right until they become equal.
- Count the number of shifts performed.
- The remaining value represents the common binary prefix.
- Left shift the common prefix back to restore its position.

Key Insight:
Any bit that changes within the range [left, right]
will become 0 after applying the AND operation across
the entire range. Only the common leading bits remain
unchanged.
------------------------------------------------------------
*/

class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int shiftCounter = 0;
        while (left != right) {
            left = left >> 1;
            right = right >> 1;
            shiftCounter++;
        }
        return left << shiftCounter;
    }
};