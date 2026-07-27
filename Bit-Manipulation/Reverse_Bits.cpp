/*
------------------------------------------------------------
Problem : Reverse Bits (LeetCode 190)
Pattern : Bit Manipulation

Time Complexity : O(1)
Space Complexity : O(1)

Idea:
- Traverse all 32 bits of the integer.
- Extract the least significant bit using (n & 1).
- Shift the result left by one position and insert
  the extracted bit.
- Right shift the original number to process the
  next bit.

Key Insight:
By repeatedly taking the least significant bit and
appending it to the left of the result, the bit order
is reversed in exactly 32 iterations without using
extra memory.
------------------------------------------------------------
*/

/*
class Solution {
public:
    int reverseBits(int n) {
        int result = 0;
        for(int i = 0; i < 32; i++) {
            int bits = n & 1;
            result = result << 1 | bits;
            n = n >> 1;
        }
        return result;
    }
};

*/
class Solution {
public:
    int reverseBits(int n) {
        deque<int> dq;
        for (int i = 0; i < 32; i++) {
            int bit = n & 1;
            dq.push_back(bit);
            n = n >> 1;
        }
        
        int result = 0;
        while (!dq.empty()) {
            int bit = dq.front();
            dq.pop_front();
            result = (result << 1) | bit;
        }
        
        return result;
    }
};