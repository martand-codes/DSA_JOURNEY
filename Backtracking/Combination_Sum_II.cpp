// Problem: Combination Sum II (LeetCode 40)
// Pattern: Backtracking + Sorting
// TC: O(2^n)
// SC: O(n)
//
// Idea:
// 1. Sort the array.
// 2. Every element can be used only once.
// 3. After exploring the "take" branch,
//    skip consecutive duplicates before
//    exploring the "not take" branch.
// 4. Backtrack after each recursive call.

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> Solution;
        int index;
        vector<int> subSet;

        //Sorting
        sort(candidates.begin(), candidates.end());

        helper(candidates, 0, subSet, Solution, target);
        return Solution;
    }

    void helper(vector<int>& candidates, int index, vector<int>& subSet, vector<vector<int>>& Solution, int target) {
        // Base Cases:
        if (target == 0) { // Answer Case
            Solution.push_back(subSet);
            return;
        }
        if(target < 0) {
            return;
        }
        if(index == candidates.size()) {
            return;
        }

        // Pushing
        subSet.push_back(candidates[index]);

        // Taking
        helper(candidates, index + 1, subSet, Solution, target - candidates[index]);

        // BackTracking
        subSet.pop_back();

        while(index + 1 < candidates.size() && candidates[index] == candidates[index + 1]){
            index++; // Skipping the duplicate after sorting
        }
        // Not Taking
        helper(candidates, index + 1, subSet, Solution, target);

    }
};
