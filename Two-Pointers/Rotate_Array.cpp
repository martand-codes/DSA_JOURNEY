/*
------------------------------------------------------------
Problem : Rotate Array (LeetCode 189)
Pattern : Array Manipulation / Two Pointers / Reversal
          Algorithm / In-Place Rotation

Time Complexity :
Rotate : O(N)

Space Complexity : O(1)

Idea:
Rotate the array to the right by k positions using
the reversal algorithm without requiring an extra array.

- Calculate the effective rotation using k = k % n.
- Reverse the entire array.
- Reverse the first k elements.
- Reverse the remaining n - k elements.

These three reversals rearrange the elements into
their correct rotated positions.

Key Insight:
Reversing the entire array followed by reversing
individual sections restores the original relative
order of elements within the two rotated partitions.

For example:
Original : [1, 2, 3, 4, 5, 6, 7]
k = 3

Reverse All : [7, 6, 5, 4, 3, 2, 1]
Reverse 1st k : [5, 6, 7, 4, 3, 2, 1]
Reverse Rest : [5, 6, 7, 1, 2, 3, 4]

N represents the number of elements in the array.

Unlike the auxiliary array approach, this method
performs rotation in-place using constant extra space.

------------------------------------------------------------
*/

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        vector<int> rotatedArray(n);

        for (int i = 0; i < n; i++) {
            rotatedArray[(i + k) % n] = nums[i];
        }

        for (int i = 0; i < n; i++) {
            nums[i] = rotatedArray[i];
        }        
    }
};