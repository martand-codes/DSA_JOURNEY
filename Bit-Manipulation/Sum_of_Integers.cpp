/*
------------------------------------------------------------
Problem : Sum of Two Integers (LeetCode 371)
Pattern : Bit Manipulation

Time Complexity : O(1)
Space Complexity : O(1)

Idea:
- XOR computes the sum without carrying.
- AND identifies the positions where carries occur.
- Left shift the carry by one position.
- Repeat until no carry remains.

Key Insight:
Binary addition can be simulated entirely using
bitwise operators. XOR performs addition without
carry, while AND followed by a left shift computes
the carry for the next iteration.
------------------------------------------------------------
*/

class Solution {
public:
    int getSum(int a, int b) {
        int currentSum = a;
        int currentCarry = b;
        while (currentCarry != 0) {
          int foundAnd = currentSum & currentCarry;
            int foundXor = currentSum ^ currentCarry;
            currentSum = foundXor;
            currentCarry = (unsigned int)(foundAnd) << 1;
        }
        return currentSum;
    }
};

