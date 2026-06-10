// Problem: 4Sum
// Pattern: Two Pointers
// TC: O(n^3)
// SC: O(1) excluding output

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        int n = nums.size();
        
        // We need at least 4 numbers to make a quadruplet
        if (n < 4) return res; 
        
        // 1. Sort the array
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < n - 3; ++i) {
            // Skip duplicates for the first number (i)
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            
            for (int j = i + 1; j < n - 2; ++j) {
                // Skip duplicates for the second number (j)
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;
                
                int left = j + 1;
                int right = n - 1;
                
                while (left < right) {
                    // Cast to long long to prevent integer overflow!
                    long long total = (long long)nums[i] + nums[j] + nums[left] + nums[right];
                    
                    if (total == target) {
                        res.push_back({nums[i], nums[j], nums[left], nums[right]});
                        
                        // Move pointers inward
                        left++;
                        right--;
                        
                        // Skip duplicates for the left pointer
                        while (left < right && nums[left] == nums[left - 1]) left++;
                        
                        // Skip duplicates for the right pointer
                        while (left < right && nums[right] == nums[right + 1]) right--;
                    } 
                    else if (total < target) {
                        left++;
                    } 
                    else {
                        right--;
                    }
                }
            }
        }
        
        return res;
    }
};