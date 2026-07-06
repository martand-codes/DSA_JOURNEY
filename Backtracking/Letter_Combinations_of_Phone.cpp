// Problem: Letter Combinations of a Phone Number (LeetCode 17)
// Pattern: Backtracking
// TC: O(4^n)
// SC: O(n)
//
// Idea:
// For every digit,
// try each possible character.
// Add it to the current string,
// recurse for the next digit,
// then backtrack.

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> Answer;
        string  subString;
        if(digits.empty()) {
            return Answer;
        }
        helper(digits, Answer, 0, subString);
        return Answer;
    }
    void helper(string& digits, vector<string>& Answer, int index, string& subString) {
        // Base Case
        if(index == digits.length()) { // Answer Case
            Answer.push_back(subString);
            return;
        }
        

        //Defining the KeyPad
        string keyPad[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

        int currentDigit = digits[index] - '0'; // To convert it into Number
        string letters = keyPad[currentDigit];

        for(int i = 0; i < letters.length(); i++ ) {
                subString.push_back(letters[i]);
                helper(digits, Answer, index + 1, subString);
                subString.pop_back();
            
        }

    }
};