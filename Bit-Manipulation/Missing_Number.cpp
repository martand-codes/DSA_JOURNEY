/*
------------------------------------------------------------
Problem : Missing Number (LeetCode 268)
Pattern : Bit Manipulation (XOR)

Time Complexity : O(N)
Space Complexity : O(1)

Idea:
- XOR all indices and all array elements.
- Initialize the answer with n since the indices
  only go from 0 to n-1.
- Every existing number cancels out with its index,
  leaving only the missing number.

Key Insight:
Since x ^ x = 0 and XOR is associative and
commutative, every matched value disappears,
leaving only the missing number.
------------------------------------------------------------
*/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int missingPeice = nums.size();
        for(int i = 0; i < nums.size(); i++) {
            missingPeice ^= i ^ nums[i];
        }
        return missingPeice;
    }
};
