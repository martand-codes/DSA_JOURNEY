/*
------------------------------------------------------------
Problem : Merge Sorted Array (LeetCode 88)
Pattern : Two Pointers

Time Complexity : O(M + N)
Space Complexity : O(1)

Idea:
- Start comparing elements from the ends of both arrays.
- Place the larger element at the end of nums1.
- Continue until all elements of nums2 have been placed.

Key Insight:
Merging from the back avoids overwriting valid elements
already present in nums1, allowing the merge to be
performed in-place without extra memory.
------------------------------------------------------------
*/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p1 = m - 1; 
        int p2 = n - 1; 
        int p = m + n - 1; 
        while (p2 >= 0) {
            if (p1 >= 0 && nums1[p1] > nums2[p2]) {
                nums1[p] = nums1[p1];
                p1--;
            } 

            else {
                nums1[p] = nums2[p2];
                p2--;
            }
            p--; 
        }
    }
};