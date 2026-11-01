/*
------------------------------------------------------------
Problem : Minimum Moves to Equal Array Elements (LeetCode #453)
Pattern : Math + Greedy + Minimum Element

Time Complexity : O(N)
Space Complexity : O(1)

Idea:
- Find the smallest element in the array.
- Treat the smallest element as the target value.
- For every other element, calculate the difference between it and the minimum.
- Sum all differences to determine the minimum number of moves.

Key Insight:
- Incrementing N-1 elements by 1 is equivalent to decrementing
  one element by 1.
- Therefore, the optimal strategy is to reduce every element
  to the minimum element.
- The total moves required are:
  SUM(nums[i] - minimum element).

------------------------------------------------------------
*/

class Solution {
public:
    int minMoves(vector<int>& nums) {
        int moves = 0;
        int smallestNum = *min_element(nums.begin(), nums.end());
        for(int num : nums) {
            moves += num - smallestNum;
        }
        return moves;
    }
};