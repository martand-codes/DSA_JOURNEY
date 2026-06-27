// Problem: Find the Maximum Number of Elements in Subset (LeetCode 3020)
// Pattern: Hash Map + Greedy + Mathematical Observation
// TC: O(n + log log M * U)
// SC: O(n)
//
// Idea:
// 1. Count the frequency of every number.
// 2. Handle 1 separately since 1² = 1.
// 3. For every other value x, repeatedly square:
//      x -> x² -> x⁴ -> ...
// 4. Every intermediate value must appear at least twice.
// 5. The last value contributes either:
//      +1 if present
//      -1 otherwise.

class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long, int> counts;
        for (int num : nums) {
            counts[num]++;
        }
        
        int max_len = 1;
        if (counts.count(1)) {
            int c = counts[1];
            max_len = max(max_len, c % 2 == 0 ? c - 1 : c);
        }
        
        for (auto const& [k, v] : counts) {
            if (k == 1) continue;
            
            long long curr = k;
            int current_len = 0;
            
            while (counts.count(curr) && counts[curr] >= 2) {
                current_len += 2;
                curr *= curr;
            }
            
            if (counts.count(curr)) {
                current_len += 1;
            } else {
                current_len -= 1;
            }
            
            max_len = max(max_len, current_len);
        }
        
        return max_len;
    }
};