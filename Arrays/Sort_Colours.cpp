/*
------------------------------------------------------------
Problem : Sort Colors (LeetCode 75)
Pattern : Two Pointers / Dutch National Flag Algorithm

Time Complexity : O(N)
Space Complexity : O(1)

Idea:
- Maintain three pointers:
    low  : next position for 0
    mid  : current element being examined
    high : next position for 2
- Maintain three regions:
    [0 ... low - 1]       → 0s
    [low ... mid - 1]     → 1s
    [mid ... high]        → Unknown
    [high + 1 ... n - 1]  → 2s
- If nums[mid] == 0, swap it with low and advance both
  low and mid.
- If nums[mid] == 1, it is already in the correct region,
  so only advance mid.
- If nums[mid] == 2, swap it with high and decrease high.
  Do not advance mid because the newly swapped element has
  not been processed yet.

Key Insight:
The array can be partitioned into three regions in a single
pass by maintaining the boundaries of 0s, 1s, and 2s. The
crucial detail is that after swapping a 2 with the high
pointer, mid must remain unchanged to process the incoming
element.

------------------------------------------------------------
*/

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0, mid = 0, high = nums.size() - 1;
        
        while (mid <= high) {
            if (nums[mid] == 0) {
                swap(nums[low++], nums[mid++]);
            } else if (nums[mid] == 1) {
                mid++;
            } else {
                swap(nums[mid], nums[high--]);
            }
        }
    }
};