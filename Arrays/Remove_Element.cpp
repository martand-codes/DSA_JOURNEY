/*
------------------------------------------------------------
Problem : Remove Element (LeetCode 27)
Pattern : Two Pointers / In-Place Array

Time Complexity : O(N)
Space Complexity : O(1)

Idea:
- Use i to scan every element of the array.
- Use k as the position where the next valid element
  should be placed.
- If nums[i] is not equal to val, copy it to nums[k]
  and increment k.
- Elements equal to val are simply skipped.
- The first k positions of nums contain all elements that
  should remain.

Key Insight:
Instead of actually removing elements, overwrite the
array in-place with the valid elements. The write pointer
k always represents the size of the resulting array.

------------------------------------------------------------
*/

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != val) {
                nums[k] = nums[i];
                k++;
            }
        }
        return k;
    }
};