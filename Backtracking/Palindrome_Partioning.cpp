// Problem: Palindrome Partitioning (LeetCode 131)
// Pattern: Backtracking + Validation
// TC: O(n × 2^n)
// SC: O(n)
//
// Idea:
// Keep the original string unchanged.
// Track the current starting index.
// Try every possible ending index.
// Validate using a two-pointer palindrome check.
// If valid, include the substring and recurse.
// Backtrack after returning.

/*

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<string> partition;
        vector<vector<string>> Answer;

        getAllPartition(s, partition, Answer);

        return Answer;
    }

    bool isPalindrome(string& s) {
        string palStr = s;
        reverse(palStr.begin(), palStr.end());
        if(s == palStr) {
            return true;
        }
        return false;
    }

    void getAllPartition(string s, vector<string>& partition, vector<vector<string>>& Answer) {
        // Base Case: 

        if (s.size() == 0) {
            Answer.push_back(partition);
            return;
        }

        string subPartition;

        for(int i = 0; i < s.size(); i++ ) {
            subPartition = s.substr(0, i + 1);

            if(isPalindrome(subPartition)) {
                partition.push_back(subPartition);
                getAllPartition(s.substr(i + 1), partition, Answer);
                partition.pop_back();
            }
        }
    }
};

*/

// Optimized

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<string> currentPartition;
        vector<vector<string>> Answer;
        
        // Pass the original string and start at index 0
        getAllPartition(s, 0, currentPartition, Answer);
        
        return Answer;
    }

    // Better Use 2 pointers 
    bool isPalindrome(const string& s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }

    void getAllPartition(const string& s, int index, vector<string>& currentPartition, vector<vector<string>>& Answer) { // Used index pointer to know the current position

        // Base Case:
        if (index == s.size()) {
            Answer.push_back(currentPartition);
            return;
        }
        for(int i = index; i < s.size(); i++) {
            
            if(isPalindrome(s, index, i)) {
                
                currentPartition.push_back(s.substr(index, i - index + 1));

                getAllPartition(s, i + 1, currentPartition, Answer);
                
                
                currentPartition.pop_back(); // Backtracking
            }
        }
    }
};