/*
------------------------------------------------------------
Problem : Counting Bits (LeetCode 338)
Pattern : Bit Manipulation

Time Complexity : O(N)
Space Complexity : O(N)

Idea:
- Iterate through every number from 0 to n.
- Count the number of set bits using Brian
  Kernighan's Algorithm.
- Store the count in the answer array.

Key Insight:
The operation (x & (x - 1)) removes the rightmost
set bit from a number. Repeating it until the
number becomes zero counts the total number of
set bits efficiently.
------------------------------------------------------------
*/

// Solved Using Brain K
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> answer;
        for(int i = 0; i <= n; i++) {
            int counter = 0;
            int currentNumber = i;
            while(currentNumber != 0){
                currentNumber = currentNumber & (currentNumber - 1);
                counter++;
            }
            answer.push_back(counter);
        }
        return answer;
    }
};

// Solved using DP
vector<int> countBits(int n) {

    vector<int> bits(n + 1, 0);

    for(int i = 1; i <= n; i++) {
        bits[i] = bits[i >> 1] + (i & 1);
    }

    return bits;
}