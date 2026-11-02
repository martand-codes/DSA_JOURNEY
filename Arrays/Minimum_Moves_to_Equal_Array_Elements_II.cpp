/*
------------------------------------------------------------
Problem : Minimum Moves to Equal Array Elements II (LeetCode #462)
Pattern : Sorting + Greedy + Median + Mathematical Optimization

Time Complexity : O(N log N)
Space Complexity : O(1) auxiliary space (excluding sorting)

Idea:
- Sort the array in ascending order.
- Select the median element at index N / 2.
- Calculate the absolute difference between every element
  and the median.
- Sum all differences to obtain the minimum number of moves.

Key Insight:
- The median minimizes the sum of absolute deviations.
- Moving every element toward the median minimizes
  the total number of increment/decrement operations.
- For an even-sized array, either middle element
  produces the same minimum cost.
- Sorting allows us to obtain the median efficiently.

------------------------------------------------------------
*/

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int median = nums[n / 2];
        int moves = 0;
        for (int num : nums) {
            moves += abs(num - median);
        }
        
        return moves;
    }
};