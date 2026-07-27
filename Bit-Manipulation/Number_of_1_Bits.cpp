/*
------------------------------------------------------------
Problem : Number of 1 Bits (LeetCode 191)
Pattern : Bit Manipulation

Time Complexity : O(1)
Space Complexity : O(1)

Idea:
- Check the least significant bit using (n & 1).
- If it is set, increment the counter.
- Right shift the number by one bit.
- Repeat until all bits are processed.

Key Insight:
The expression (n & 1) determines whether the
least significant bit is 1. Repeatedly shifting
the number right allows us to examine every bit.
------------------------------------------------------------
*/

class Solution {
public:
    int hammingWeight(int n) {
        int counter = 0; 
        while(n != 0) {
            if(n & 1)  {
                counter++;
            }
            n = n >> 1;
        }
        return counter;
    }
};