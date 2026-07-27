/*
------------------------------------------------------------
Problem : Minimum Array End (LeetCode 3133)
Pattern : Bit Manipulation

Time Complexity : O(1)
Space Complexity : O(1)

Idea:
- Start with x as the initial result.
- Traverse the bit positions from least significant
  to most significant.
- Whenever a bit in x is 0, fill it using the next
  available bit from (n - 1).
- Continue until all bits of (n - 1) are placed.

Key Insight:
The set bits of x must remain unchanged. The minimum
possible answer is obtained by inserting the binary
representation of (n - 1) only into the zero-bit
positions of x.
------------------------------------------------------------
*/

class Solution {
public:
    long long minEnd(int n, int x) {
        long long result = x;
        long long remaining = n - 1;
        long long position = 1; 
        
        while (remaining > 0) {

            if ((result & position) == 0) {
                long long bit = remaining & 1;

                if (bit == 1) {
                    result = result | position;
                }
                remaining = remaining >> 1;
            }
            position = position << 1;
        }
        
        return result;
    }
};