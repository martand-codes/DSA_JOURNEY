// Problem: Combinations (LeetCode 77)
// Pattern: Backtracking
// TC: O(C(n,k) * k)
// SC: O(k)
//
// Idea:
// At every number from 1 to n:
// 1. Include it in the current combination.
// 2. Exclude it.
// When the subset size becomes k,
// store the current combination.

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> Answer;
        vector<int> subSet;
        helper(1, subSet, Answer, n, k);
        return Answer;
    }
    void helper( int currentNumber, vector<int>& subSet, vector<vector<int>>& Answer,int n, int k) {
        
        // Base cases: 
        if(subSet.size() == k) { // Answer Case
            Answer.push_back(subSet);
            return;
        }
        if (currentNumber > n) {
            return;
        } 

        // Pruning
        if(subSet.size() + (n - currentNumber + 1) < k) {
            return;
        }

        // Pushing
        subSet.push_back(currentNumber);

        // Taking
        helper(currentNumber + 1, subSet, Answer, n, k);
        subSet.pop_back(); // BackTracking

        // Not Taking
        helper(currentNumber + 1, subSet, Answer,n, k);

    }
};