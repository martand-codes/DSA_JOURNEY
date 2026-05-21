// Problem: Rotated Sorted Array
// Approach: Divide And Conquer (Using modified binary Search)
// TC: O(log n)
// SC: O(1)


class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        
        while (left <= right) {
            // Calculate mid to avoid potential integer overflow
            int mid = left + (right - left) / 2;
            
            // If we found the target return its index
            if (nums[mid] == target) {
                return mid;
            }
            
            // Check if the left half is sorted
            if (nums[left] <= nums[mid]) {
                // If the target falls within the bounds of the sorted left half
                if (nums[left] <= target && target < nums[mid]) {
                    // Discard the right half
                    right = mid - 1; 
                } else {
                    // Otherwise, discard the left half
                    left = mid + 1;  
                }
            } 
            // If the left half is not sorted the right half must be sorted
            else {
                // If the target falls within the bounds of the sorted right half
                if (nums[mid] < target && target <= nums[right]) {
                    // Discard the left half
                    left = mid + 1;  
                } else {
                    // Otherwise discard the right half
                    right = mid - 1; 
                }
            }
        }
        
        // Target was not found in the array
        return -1;
    }
};