/*
------------------------------------------------------------
Problem : Longest Strictly Increasing or Strictly
          Decreasing Subarray (LeetCode 3105)
Pattern : Array / Dynamic Programming / Greedy /
          Rolling Variables

Time Complexity :
LongestMonotonicSubarray : O(N)

Space Complexity : O(1)

Idea:
Find the longest contiguous subarray that is either
strictly increasing or strictly decreasing.

Maintain three variables:
- up   : Length of the current strictly increasing
         subarray ending at the current index.
- down : Length of the current strictly decreasing
         subarray ending at the current index.
- best : Maximum monotonic subarray length encountered.

During traversal:
- If nums[i - 1] < nums[i], extend the increasing
  subarray; otherwise, reset up to 1.
- If nums[i - 1] > nums[i], extend the decreasing
  subarray; otherwise, reset down to 1.
- Update best using the maximum of best, up, and down.

Key Insight:
A strictly monotonic subarray can only be extended
when the adjacent elements satisfy the corresponding
strict inequality.

Maintaining increasing and decreasing lengths
simultaneously allows both patterns to be evaluated
in a single traversal without storing additional arrays.

Equal adjacent elements break both monotonic sequences.

N represents the number of elements in the array.

The algorithm processes every element once and uses
constant auxiliary space.

------------------------------------------------------------
*/

class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int best = 1, up = 1, down = 1;
        for (size_t i = 1; i < nums.size(); ++i) {
            up = nums[i - 1] < nums[i] ? up + 1 : 1; 
            down = nums[i - 1] > nums[i] ? down + 1 : 1;  
            best = max({best, up, down});
        }
        return best;
    }
};