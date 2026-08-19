/*
------------------------------------------------------------
Problem : Find the Duplicate Number (LeetCode 287)
Pattern : Floyd's Cycle Detection / Fast & Slow Pointers

Time Complexity : O(N)
Space Complexity : O(1)

Idea:
- Treat the array as a linked list where the value at
  each index points to the next index.
- Because one number is duplicated, a cycle must exist.
- Use Floyd's Cycle Detection algorithm:
  - slow moves one step.
  - fast moves two steps.
- Once slow and fast meet, reset slow to the beginning.
- Move both pointers one step at a time.
- Their second meeting point is the duplicate number.

Key Insight:
Although this is an array problem, the relationship

    index → nums[index]

allows the array to be interpreted as a linked-list-like
structure. The duplicate number creates a cycle, making
Floyd's cycle detection applicable.

Why O(1) Space:
No sorting, hash set, or modification of the input array
is required.

------------------------------------------------------------
*/


class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];

        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        while(slow != fast);
        slow = nums[0];
        while(slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};