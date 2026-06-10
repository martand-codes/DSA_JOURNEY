class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        
        // Use an array for mapping: index 2 corresponds to "abc", etc.
        vector<string> phone_map = {
            "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
        };
        
        vector<string> res;
        string current_string = "";
        
        backtrack(digits, 0, phone_map, current_string, res);
        
        return res;
    }
    
private:
    void backtrack(const string& digits, int index, const vector<string>& phone_map, 
                   string& current_string, vector<string>& res) {
                       
        // Base Case: We've formed a complete combination
        if (index == digits.length()) {
            res.push_back(current_string);
            return;
        }
        
        // Find the mapped letters for the current digit
        string letters = phone_map[digits[index] - '0'];
        
        // Loop through the letters
        for (char letter : letters) {
            // DO: Add the letter
            current_string.push_back(letter);
            
            // RECURSE: Move to the next digit
            backtrack(digits, index + 1, phone_map, current_string, res);
            
            // UNDO (Backtrack): Remove the letter so we can try the next one
            current_string.pop_back(); 
        }
    }
};