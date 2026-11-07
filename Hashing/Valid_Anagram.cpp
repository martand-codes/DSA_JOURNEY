/*
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
*/

// Solved using Hashing

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) {
            return false;
        }
        unordered_map<char, int> frequency;
        for(int i = 0; i < s.size(); i++){
            frequency[s[i]]++;
        }
        for(int i = 0; i < t.size(); i++) {
            if(!frequency.count(t[i])) {
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