// Problem: Combination Sum III (LeetCode 216)
// Pattern: Backtracking
// TC: O(2^9)
// SC: O(k)
//
// Idea:
// Choose numbers from 1 to 9.
// At each step:
// 1. Include the current number.
// 2. Exclude the current number.
// Stop when exactly k numbers sum to n.

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> Answer;
        vector<int> subSet;
        helper(1, n, k, subSet, Answer);
        return Answer;
    }
    void helper(int currentNumber, int n, int k, vector<int>& subSet, vector<vector<int>>& Answer) {
        
        // Base Cases:
        if (subSet.size() == k && n == 0) {  // Answer Case
            Answer.push_back(subSet);
            return;
        }
        if (n  < 0) {
            return;
        }
        if (currentNumber > 9 || subSet.size() >= k) { // Stop if we go past 9 or exceed size k
            return;
        }

        // pushing
        subSet.push_back(currentNumber);

        // Taking
        helper(currentNumber + 1, n - currentNumber, k, subSet, Answer);
        subSet.pop_back(); // Backtracking

        // Not Taking
        helper(currentNumber + 1, n, k, subSet, Answer);
    }
};