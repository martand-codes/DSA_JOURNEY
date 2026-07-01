// Problem: Permutations 
// Pattern: Backtracking + Swapping
// TC: O(n × n!)
// SC: O(n)
//
// Idea:
// Fix one position at a time.
// Swap every possible candidate into the current position.
// Recurse for the remaining positions.
// Swap back to restore the original array.

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> Answer;
        helper(nums, 0, Answer);
        return Answer;
    }

    void helper(vector<int>& nums, int index, vector<vector<int>>& Answer) {
        // Base Case:
        if(index == nums.size()) {
            Answer.push_back(nums);
            return;
        }

        // Pushing
        for(int i = index; i < nums.size(); i++) {
            swap(nums[index], nums[i]);
            helper(nums, index + 1, Answer);

            swap(nums[index], nums[i]); // BackTracking
        }

        

    }
};