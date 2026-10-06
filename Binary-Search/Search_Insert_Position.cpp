/*
------------------------------------------------------------
Problem : Search Insert Position (LeetCode 35)
Pattern : Binary Search

Time Complexity : O(log N)
Space Complexity : O(1)

Idea:
- Perform binary search on the sorted array.
- If the target is found, return its index.
- If nums[mid] < target, search the right half.
- Otherwise, search the left half.
- If the target is not found, return `left`.

Key Insight:
When the loop ends, `left` points to the first position
where the target can be inserted while keeping the array
sorted.

Therefore:

    left = insertion position

This is also known as finding the lower bound of the target.

------------------------------------------------------------
*/


class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
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
        return left;
    }
};