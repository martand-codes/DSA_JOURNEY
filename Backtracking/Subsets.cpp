// Problem: Subsets (LeetCode 78)
// Pattern: Backtracking / Recursion
// TC: O(n × 2^n)
// SC: O(n)
//
// Idea:
// At every index we have two choices:
// 1. Include the current element.
// 2. Exclude the current element.
//
// Generate every possible subset using recursion.
// Undo the choice (backtrack) before exploring the next branch.

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        // Redefining
        vector<vector<int>> result; // Because the Result is an array of su
        vector<int> subSet;
        helper(nums, 0, subSet, result);
        return result;
    }

    void helper (vector<int>& nums, int index, vector<int>& subSet, vector<vector<int>>& result) {
        
        // Base Case:
        if (index == nums.size()) {
            result.push_back(subSet);
            return;
        }
        // Taking
        subSet.push_back(nums[index]);
        helper(nums, index + 1, subSet, result);

        subSet.pop_back(); // BackTracking

        // Not Taking
        helper(nums, index + 1, subSet, result);
    }
};