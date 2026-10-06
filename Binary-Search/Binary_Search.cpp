/*
------------------------------------------------------------
Problem : Binary Search (LeetCode 704)
Pattern : Binary Search

Time Complexity : O(log N)
Space Complexity : O(1)

Idea:
- Maintain a search range using left and right pointers.
- Find the middle element of the current range.
- If nums[mid] is the target, return mid.
- If nums[mid] is smaller than the target, search the
  right half.
- Otherwise, search the left half.
- If the search range becomes empty, the target does not
  exist in the array.

Key Insight:
Because the array is sorted, every comparison with the
middle element allows us to eliminate half of the remaining
search space.

The middle index is calculated as:

    left + (right - left) / 2

instead of:

    (left + right) / 2

to avoid potential integer overflow.

------------------------------------------------------------
*/


class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return -1;
    }
};