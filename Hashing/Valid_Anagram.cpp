// Problem: Valid Anagram

// Brute Force Approach

// TC: O(nlogn)
// SC: O(1) or O(log n) (due to recursion stack)

class Solution {
public:
    bool isAnagram(string s, string t) {
        // If lengths differ they can't be anagrams
        if (s.length() != t.length()) {
            return false;
        }
        
        // Sorting both strings
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        
        // Comparing the sorted strings
        return s == t;
    }
};

// Optimized Approach: Hashing

// TC: O(n)
// SC: O(26) or O(1)

class Solution {
public:
    bool isAnagram(string s, string t) {

        if (s.length() != t.length()) {
            return false;
        }

        vector<int> freq(26, 0);

        for (int i = 0; i < s.length(); i++) {
            freq[s[i] - 'a']++;
            freq[t[i] - 'a']--;
        }

        for (int count : freq) {
            if (count != 0) {
                return false;
            }
        }

        return true;
    }
};

// Solved Using Hashing
class Solution {
public:
    bool isAnagram(string s, string t) {
        // Base Case:
        if(s.size() != t.size()) {
            return false;
        }
        unordered_map<char, int> frequency; // We will First insert the frequencies of string s
        for(int i = 0; i < s.size(); i++){
            frequency[s[i]]++;
        }
        // Now Checking string t from hashed table of s
        for(int i = 0; i < t.size(); i++) {
            if(frequency.count(t[i]) == 0) {
                return false;
            }
            frequency[t[i]]--;
            if(frequency[t[i]] == 0) {
                frequency.erase(t[i]);
            } 
        }
        return true;
    }
};
