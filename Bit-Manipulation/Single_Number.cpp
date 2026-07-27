/*
------------------------------------------------------------
Problem : Single Number (LeetCode 136)
Pattern : Bit Manipulation (XOR)

Time Complexity : O(N)
Space Complexity : O(1)

Idea:
- Traverse the array and XOR every element.
- Duplicate numbers cancel each other because
  x ^ x = 0.
- The remaining value is the unique number.

Key Insight:
XOR is associative and commutative. Every repeated
number eliminates itself, leaving only the element
that appears exactly once.
------------------------------------------------------------
*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int answer = 0;
        for(int i = 0; i < nums.size(); i++) {
            answer = answer ^ nums[i]; // As Xor destroyes repeating number
        }
        return answer;
    }
};