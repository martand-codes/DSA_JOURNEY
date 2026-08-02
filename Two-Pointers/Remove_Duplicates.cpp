/*
------------------------------------------------------------
Problem : Remove Duplicates from Sorted Array (LeetCode 26)
Pattern : Two Pointers (Same Direction)

Time Complexity : O(N)
Space Complexity : O(1)

Idea:
- Maintain two pointers:
  - slow: points to the last unique element.
  - fast: scans the array.
- Whenever a new unique element is found, move
  the slow pointer forward and overwrite the next
  position with the new value.
- The first (slow + 1) elements contain all unique
  values.

Key Insight:
Since the array is already sorted, duplicate values
are adjacent. A slow pointer tracks the position
where the next unique element should be placed.
------------------------------------------------------------
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
       
        if (nums.empty()) {
            return 0;
        }
        
        int slow = 0; 
        
        
        for (int fast = 1; fast < nums.size(); ++fast) {
           
            if (nums[fast] != nums[slow]) {
                slow++; 
                nums[slow] = nums[fast]; 
            }
        }
        

        return slow + 1;
    }
};