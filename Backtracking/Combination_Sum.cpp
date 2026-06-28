// Problem: Combination Sum (LeetCode 39)
// Pattern: Backtracking / DFS
// TC: O(2^target) (problem dependent)
// SC: O(target)
//
// Idea:
// At every index we have two choices:
// 1. Take the current element (stay at the same index since reuse is allowed).
// 2. Skip the current element (move to the next index).
//
// Backtrack after exploring the "take" branch.

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
         vector<vector<int>> answer;
         int index = 0;
         vector<int> subSets;

         helper(nums, 0, subSets, answer, target);

         return answer;
    }

    void helper (vector<int>& nums, int index, vector<int>& subSets, vector<vector<int>>& answer, int target) {
        // Base Cases:

        if(index == nums.size()) {
            return;
        }
        // Ans Case:
        if (target == 0) {
            answer.push_back(subSets);
            return;
        }
        if (target < 0) {
            return;
        }

        subSets.push_back(nums[index]);

        helper(nums, index, subSets, answer, target - nums[index]); // When we Want to push multiple times or One Time

        subSets.pop_back(); // BackTracking
        helper(nums, index + 1, subSets, answer, target);


    }
};
