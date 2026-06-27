// Problem: Sum of All Subset XOR Totals (LeetCode 1863)
// Pattern: Recursion / Backtracking
// TC: O(2^n)
// SC: O(n)

// Idea:
// At every index we have two choices:
// 1. Include the current element in the XOR.
// 2. Exclude the current element.

// When we reach the end of the array,
// the accumulated XOR contributes to the final answer.

class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        return helper(nums, 0, 0);
    }

    int helper(vector<int> &nums, int index, int xorTotal) {

        // Base Case
        if(index == nums.size()) {
            return xorTotal;
        }

        // Taking the Element
        int take = helper(nums, index + 1, xorTotal ^ nums[index]);

        // Not Taking
        int noTake = helper(nums, index + 1, xorTotal);

        return take + noTake; // Returning the total Sum to the Original Function
    }
};