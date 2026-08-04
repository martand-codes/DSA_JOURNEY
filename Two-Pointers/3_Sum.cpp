/*
------------------------------------------------------------
Problem : 3Sum (LeetCode 15)
Pattern : Sorting + Two Pointers

Time Complexity : O(N²)
Space Complexity : O(1)
(Excluding the output array)

Idea:
- Sort the array.
- Fix one element at a time.
- Use two pointers to find two remaining values
  whose sum equals the negative of the fixed value.
- Skip duplicate values to avoid repeated triplets.

Key Insight:
Sorting transforms the problem into multiple
Two Sum II problems. Using two pointers for each
fixed element reduces the complexity from O(N³)
to O(N²).
------------------------------------------------------------
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < n - 2; ++i) {
            if (nums[i] > 0) break;
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            
            int left = i + 1;
            int right = n - 1;
            
            while (left < right) {
                int total = nums[i] + nums[left] + nums[right];
                
                if (total == 0) {
                    res.push_back({nums[i], nums[left], nums[right]});
                    left++;
                    right--;
                    while (left < right && nums[left] == nums[left - 1]) left++;
                    while (left < right && nums[right] == nums[right + 1]) right--;
                    
                } else if (total < 0) {
                    left++; 
                } else {
                    right--; 
                }
            }
        }
        
        return res;
    }
};