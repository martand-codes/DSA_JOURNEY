// Problem: Find K-th Character in Processed String
// Pattern: Reverse Simulation / String Construction Optimization
// TC: O(n)
// SC: O(n)
//
// Idea:
// 1. Track only the length of the virtual string after each operation.
// 2. Work backwards from index k.
// 3. Reverse-map k through operations:
//    '*' -> skip
//    '#' -> k %= previous_length
//    '%' -> mirror index
//    letter -> check if k points to this character
//
// Avoids constructing exponentially large strings.


class Solution {
public:
    char processStr(string s, long long k) {
        int n = s.length();
        vector<long long> lengths(n, 0);
        long long cur_len = 0;
        
        for (int i = 0; i < n; i++) {
            if (s[i] == '*') {
                cur_len = max(0LL, cur_len - 1);
            } else if (s[i] == '#') {
                cur_len *= 2;
            } else if (s[i] == '%') {
                // Length stays the same
            } else {
                cur_len += 1;
            }
            lengths[i] = cur_len;
        }
        
        if (k >= lengths.back()) {
            return '.';
        }
        
        long long curr_k = k;
        
        for (int i = n - 1; i >= 0; i--) {
            long long prev_len = (i > 0) ? lengths[i - 1] : 0;
            
            if (s[i] == '*') {
                continue;
            } else if (s[i] == '#') {
                curr_k %= prev_len;
            } else if (s[i] == '%') {
                curr_k = prev_len - 1 - curr_k;
            } else {
                if (curr_k == prev_len) {
                    return s[i];
                }
            }
        }
        
        return '.';
    }
};