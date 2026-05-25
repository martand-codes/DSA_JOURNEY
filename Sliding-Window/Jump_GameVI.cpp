// Problem: Jump Game VII
// Pattern: Dynamic Programming + Sliding Window
// TC: O(n)
// SC: O(n)

class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.length();
        
        // Quick optimization: If the last character is '1' we can never land on it
        if (s[n - 1] == '1') {
            return false;
        }
        
        // dp[i] represents whether we can reach index i
        vector<bool> dp(n, false);
        dp[0] = true; // We always start at index 0
        
        int active_count = 0; // Tracks the number of reachable indices in our sliding window
        
        for (int i = 1; i < n; ++i) {
            // 1. Add the state of the index that just entered our valid jump window
            if (i >= minJump && dp[i - minJump]) {
                active_count++;
            }
            
            // 2. Remove the state of the index that just fell behind our valid jump window
            if (i > maxJump && dp[i - maxJump - 1]) {
                active_count--;
            }
            
            // 3. We can reach current index if it's 0 AND we have a valid launch pad in the window
            if (s[i] == '0' && active_count > 0) {
                dp[i] = true;
            }
        }
        
        return dp[n - 1];
    }
};