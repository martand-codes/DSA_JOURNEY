/*
------------------------------------------------------------
Problem : Minimum Sum of Subarray of Size Range
          (LeetCode 3364)
Pattern : Array / Brute Force / Nested Loops /
          Subarray Enumeration

Time Complexity :
MinimumSumSubarray : O(N * R)

Space Complexity : O(1)

Idea:
Find the minimum positive sum among all contiguous
subarrays whose lengths lie within the range [l, r].

- Initialize min_sum to INT_MAX.
- Traverse the array using an outer loop to select
  the starting index of each subarray.
- Initialize current_sum to zero for every starting
  index.
- Use an inner loop to extend the subarray.
- Incrementally accumulate elements into current_sum.
- Calculate the current subarray length using
  j - i + 1.
- If the length lies within [l, r]:
  - Check whether current_sum is positive.
  - Update min_sum with the smallest valid sum.
- Stop extending when the subarray length exceeds r,
  since longer subarrays are no longer valid.

Finally:
- Return min_sum if a valid positive subarray exists.
- Otherwise, return -1.

Key Insight:
A subarray sum can be calculated incrementally
by extending the previous subarray with one element.

The maximum permitted subarray length r allows the
inner loop to terminate early, avoiding unnecessary
traversal beyond the required range.

Only positive subarray sums are considered valid,
even when the subarray length satisfies [l, r].

N represents the number of elements in the array.
R represents the maximum permitted subarray length.

The outer loop considers every starting position,
while the inner loop examines at most r elements,
resulting in O(N * R) time.

The algorithm uses only a few integer variables,
requiring constant auxiliary space.

------------------------------------------------------------
*/

class Solution {
public:
    int minimumSumSubarray(std::vector<int>& nums, int l, int r) {
        int n = nums.size();
        int min_sum = INT_MAX;
        
        for (int i = 0; i < n; ++i) {
            int current_sum = 0;
            for (int j = i; j < n; ++j) {
                current_sum += nums[j];
                int len = j - i + 1;
                
                // If length is within the range [l, r]
                if (len >= l && len <= r) {
                    if (current_sum > 0) {
                        min_sum = std::min(min_sum, current_sum);
                    }
                }
                
                // If length exceeds r, no need to extend further for this starting index i
                if (len > r) {
                    break;
                }
            }
        }
        
        return (min_sum == INT_MAX) ? -1 : min_sum;
    }
};