// Problem: Count the Number of Special Characters II
// Pattern: Hashing / String Processing
// TC: O(n)
// SC: O(1)


class Solution {
public:
    int numberOfSpecialChars(string word) {
        // -1 represents that we haven't seen the character yet
        vector<int> last_lower(26, -1);
        vector<int> first_upper(26, -1);
        
        for (int i = 0; i < word.length(); ++i) {
            char c = word[i];
            
            if (islower(c)) {
                // Continually overwrite to keep the most recent (last) index
                last_lower[c - 'a'] = i;
            } else {
                int idx = c - 'A';
                // Only write the index if it's the very first time we see the uppercase letter
                if (first_upper[idx] == -1) {
                    first_upper[idx] = i;
                }
            }
        }
        
        int special_count = 0;
        
        for (int i = 0; i < 26; ++i) {
            // Check if both exist, and if the last lowercase is strictly before the first uppercase
            if (last_lower[i] != -1 && first_upper[i] != -1 && last_lower[i] < first_upper[i]) {
                special_count++;
            }
        }
        
        return special_count;
    }
};