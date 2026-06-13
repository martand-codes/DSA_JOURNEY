// Problem: Map Word Weights
// Pattern: String Processing / Simulation
// TC: O(total_characters)
// SC: O(1) excluding output string
//
// Idea:
// Sum character weights for each word,
// take modulo 26,
// map result to reverse alphabet.

class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string res = "";
        
        for (const string& word : words) {
            int word_weight = 0;
            
            // 1. Sum the weights for the current word
            for (char c : word) {
                word_weight += weights[c - 'a'];
            }
            
            // 2. Modulo 26
            int mod_val = word_weight % 26;
            
            // 3. Map to reverse alphabet and append
            res += (char)('z' - mod_val);
        }
        
        return res;
    }
};