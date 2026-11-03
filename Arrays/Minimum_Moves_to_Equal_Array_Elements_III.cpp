/*
------------------------------------------------------------
Problem : Minimum Moves to Equal Array Elements (LeetCode 453)
Pattern : Greedy / Mathematical Reduction

Time Complexity : O(N)
Space Complexity : O(1)

Idea:
- Find the maximum element in the array.
- Calculate the difference between the maximum and every other element.
- Sum these differences to determine the minimum moves.

Key Insight:
- Incrementing N-1 elements by 1 is equivalent to decrementing
  one element by 1.
- Therefore, the optimal strategy is to reduce every element
  to the minimum element.

------------------------------------------------------------
*/

class Solution {
public:
    int minMoves(vector<int>& nums) {
        int max_val = *max_element(nums.begin(), nums.end());
        int moves = 0;
        for (int num : nums) {
            moves += (max_val - num);
        }
        return moves;
    }
};