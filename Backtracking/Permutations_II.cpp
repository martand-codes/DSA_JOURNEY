// Problem: Permutations II 
// Pattern: Backtracking + Swapping
// TC: O(n × n!)
// SC: O(n)
//
// Idea:
// Sort the array.
// Fix one position at a time.
// Before swapping, ensure the same value has not
// already been used at the current recursion level.
// Swap back after recursion.

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> Answer;
        sort(nums.begin(), nums.end());
        helper(nums, 0, Answer);
        return Answer;
    }

    void helper(vector<int>& nums, int index, vector<vector<int>>& Answer) {
        // Base Cases:

        if(index == nums.size()) {
            Answer.push_back(nums);
            return;
        }

        for(int i = index; i < nums.size(); i++) {

            bool alreadySwapped = false;
            for (int j = index; j < i; j++) {
                if (nums[j] == nums[i]) {
                    alreadySwapped = true;
                    break;
                }
            }
            if (alreadySwapped) {
                continue; // Skip the duplicate
            }

            swap(nums[index], nums[i]);

            helper(nums, index + 1, Answer);

            // Backtracking
            swap(nums[index], nums[i]);
        }
    }
};