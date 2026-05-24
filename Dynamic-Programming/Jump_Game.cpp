// Problem: Jump Game V
// Pattern: DFS + Memoization (Dynamic Programming)
// TC: O(n * d)
// SC: O(n)

class Solution {
public:
    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
        // dp[i] stores the max indices visited starting from index i
        vector<int> dp(n, 0); 
        int max_total_jumps = 0;
        
        // We can start at any index, so we test all of them
        for (int i = 0; i < n; ++i) {
            max_total_jumps = max(max_total_jumps, dfs(arr, d, i, dp));
        }
        
        return max_total_jumps;
    }
    
private:
    int dfs(const vector<int>& arr, int d, int i, vector<int>& dp) {
        // If we have already computed the result for this index return it
        if (dp[i] != 0) {
            return dp[i];
        }
        
        int n = arr.size();
        int max_jumps = 1; // We always visit at least the starting index
        
        // 1. Try jumping to the Right
        for (int j = i + 1; j <= min(i + d, n - 1); ++j) {
            // We cannot jump over or onto an element taller or equal to arr[i]
            if (arr[j] >= arr[i]) {
                break; 
            }
            max_jumps = max(max_jumps, 1 + dfs(arr, d, j, dp));
        }
        
        // 2. Try jumping to the Left
        for (int j = i - 1; j >= max(i - d, 0); --j) {
            // We cannot jump over or onto an element taller or equal to arr[i]
            if (arr[j] >= arr[i]) {
                break; 
            }
            max_jumps = max(max_jumps, 1 + dfs(arr, d, j, dp));
        }
        
        // Save the computed result in our DP array
        dp[i] = max_jumps;
        return dp[i];
    }
};