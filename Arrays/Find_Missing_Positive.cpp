/*
------------------------------------------------------------
Problem : First Missing Positive (LeetCode #41)
Pattern : Array + In-Place Hashing + Cyclic Sort

Time Complexity : O(N)
Space Complexity : O(1)

Idea:
- Traverse the array and place every valid positive number
  in its correct index.
- A number x belongs at index x - 1.
- Keep swapping while the current number is within [1, N]
  and is not already at its correct position.
- Traverse the array again.
- The first index i where nums[i] != i + 1 indicates
  that i + 1 is the smallest missing positive integer.
- If every position is correct, return N + 1.

Key Insight:
- We can use array indices as a substitute for a hash table.
- Each positive number x in the range [1, N] maps to index x - 1.
- The duplicate check prevents infinite swapping when
  the same number appears more than once.
- This achieves linear time and constant auxiliary space
  without sorting or using an extra data structure.

------------------------------------------------------------
*/

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();        
        for (int i = 0; i < n; ++i) {
            while (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        for (int i = 0; i < n; ++i) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }
        return n + 1;
    }
};