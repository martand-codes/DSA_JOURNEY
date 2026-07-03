// Problem: Subsets II (LeetCode 90)
// Pattern: Backtracking + Sorting
// TC: O(n × 2^n)
// SC: O(n)
//
// Idea:
// Sort the array.
// At every index:
// 1. Include the current element.
// 2. Exclude it.
// Before exploring the exclude branch,
// skip consecutive duplicate values.

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> subSet;
        vector<vector<int>> Answer;
        sort(nums.begin(), nums.end());
        helper(nums, 0, subSet, Answer);
        return Answer;
    }

    void helper(vector<int>& nums, int index, vector<int>& subSet, vector<vector<int>>& Answer) {
        // Base Case:
        if(index == nums.size()) {
            Answer.push_back(subSet);
            return;
        }

        subSet.push_back(nums[index]);

        helper(nums, index + 1, subSet, Answer);

        subSet.pop_back();

        while(index + 1 < nums.size() && nums[index + 1] == nums[index]) {
            index ++;
        }

         helper(nums, index + 1, subSet, Answer);
    }
};