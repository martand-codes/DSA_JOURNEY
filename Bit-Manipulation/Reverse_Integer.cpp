/*
------------------------------------------------------------
Problem : Reverse Integer (LeetCode 7)
Pattern : Math

Time Complexity : O(log₁₀N)
Space Complexity : O(1)

Idea:
- Extract the last digit using modulo.
- Remove the last digit from the number.
- Before appending the digit to the reversed number,
  check whether multiplying by 10 would overflow.
- If overflow would occur, return 0.
- Otherwise append the digit and continue.

Key Insight:
Overflow must be checked before performing
reverseNumber * 10 + digit, because signed integer
overflow is undefined behaviour in C++.
------------------------------------------------------------
*/

class Solution {
public:
    int reverse(int x) {
        int reverseNumber = 0;
        
        while (x != 0) {
            int remainder = x % 10;
            x /= 10;
            
            if (reverseNumber > INT_MAX / 10 || (reverseNumber == INT_MAX / 10 && remainder > 7)) {
                return 0;
            }
            
            if (reverseNumber < INT_MIN / 10 || (reverseNumber == INT_MIN / 10 && remainder < -8)) {
                return 0;
            }
            
            reverseNumber = reverseNumber * 10 + remainder;
        }
        
        return reverseNumber;
    }
};