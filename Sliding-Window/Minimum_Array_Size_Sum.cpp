/*
------------------------------------------------------------
Problem : Minimum Size Subarray Sum (LeetCode 209)

Pattern : Sliding Window / Two Pointers /
          Variable-Size Window / Subarray Sum

Time Complexity :
MinSubArrayLen : O(N)

Space Complexity : O(1)

Idea:
Find the minimum length of a contiguous subarray whose
sum is greater than or equal to the given target.

- Initialize two pointers:
  - i represents the starting index of the window.
  - j represents the ending index of the window.
- Initialize sum to zero to maintain the current
  window sum.
- Initialize answer to INT_MAX to track the minimum
  valid subarray length.

Sliding Window:
- Traverse the array using j as the right boundary.
- Add nums[j] to the current window sum.
- While the current sum is greater than or equal
  to target:
  - Calculate the current window length using
    j - i + 1.
  - Update answer with the minimum valid length.
  - Remove nums[i] from the current window sum.
  - Move i forward by one position to shrink
    the window and search for a shorter valid subarray.
- Move j forward to expand the window.

Finally:
- If answer remains INT_MAX, no valid subarray exists,
  so return 0.
- Otherwise, return answer as the minimum length
  of a valid contiguous subarray.

Key Insight:
The sliding window works because all array elements
are positive integers.

Expanding the window by moving j forward increases
or maintains the current sum.

Once the current sum becomes greater than or equal
to target, the window is valid.

Instead of continuing to expand the window, we shrink
it from the left to find a shorter valid subarray.

Every time a valid window is found, its length is
recorded before removing the leftmost element.

This guarantees that all potentially optimal window
boundaries are considered without repeatedly calculating
subarray sums from scratch.

N represents the number of elements in the input array.

The right pointer traverses the array at most N times,
and the left pointer also moves forward at most N times.

Each element is added to and removed from the running
sum at most once.

Therefore, the overall time complexity is O(N).

The algorithm uses only a few integer variables
and two pointers, requiring constant auxiliary space.

------------------------------------------------------------
*/

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i = 0, j = 0, sum = 0, answer = INT_MAX;

        while(j < nums.size()) {
            sum += nums[j];
            while(sum >= target) {
                answer = min(answer, j - i + 1);
                sum -= nums[i];
                i++;
            }
            j++;
        }
        return (answer == INT_MAX) ? 0 : answer;
    }
};