/*
------------------------------------------------------------
Problem : 4Sum (LeetCode 18)
Pattern : Sorting + Two Pointers + Duplicate Skipping

Time Complexity : O(N^3)
Space Complexity : O(1) auxiliary space
                   (excluding the output and sorting stack)

Idea:
- Sort the array in ascending order.
- Fix the first element using index i.
- Fix the second element using index j.
- Use two pointers, left and right, to find the remaining
  two elements whose sum equals the target.
- Calculate the sum using long long to prevent integer
  overflow.
- Skip duplicate values at every level to avoid generating
  duplicate quadruplets.
- If the sum is smaller than the target, increment left.
- If the sum is greater than the target, decrement right.
- If the sum equals the target, store the quadruplet and
  move both pointers inward.

Key Insight:
After sorting, fixing two elements reduces the problem
to finding a pair using the Two Sum two-pointer technique.

    nums[i] + nums[j] + nums[left] + nums[right] = target

Because the array is sorted:
- A sum that is too small requires a larger value.
- A sum that is too large requires a smaller value.

Skipping duplicates for i, j, left, and right ensures
that every unique quadruplet is added only once.

------------------------------------------------------------
*/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        int n = nums.size();;
        if (n < 4) return res; 
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < n - 3; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
         
            for (int j = i + 1; j < n - 2; ++j) {

                if (j > i + 1 && nums[j] == nums[j - 1]) continue;
                
                int left = j + 1;
                int right = n - 1;
                
                while (left < right) {
                    long long total = (long long)nums[i] + nums[j] + nums[left] + nums[right];
                    if (total == target) {
                        res.push_back({nums[i], nums[j], nums[left], nums[right]});
                        left++;
                        right--;
                        while (left < right && nums[left] == nums[left - 1]) left++;
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