// Problem: First Missing Positive
// Pattern: Cyclic Sort / Index Placement
// TC: O(n)
// SC: O(1)

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        
        for (int i = 0; i < n; ++i) {
            // We want to place every positive integer x (where 1 <= x <= n) 
            // at index x - 1. 
            // We swap until the current element is out of bounds or already 
            // sitting in its correct place.
            while (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        
        // After placing everything we can, the first index 'i' that 
        // doesn't contain 'i + 1' is our missing positive integer.
        for (int i = 0; i < n; ++i) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }
        
        // If the array contains exactly 1 to n, the next positive is n + 1
        return n + 1;
    }
};