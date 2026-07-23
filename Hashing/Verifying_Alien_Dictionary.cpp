/*
------------------------------------------------------------
Problem : Verifying an Alien Dictionary (LeetCode 953)
Pattern : Hashing + String Comparison
Time Complexity : O(N × M)
Space Complexity : O(1)

Idea:
- Build a rank array that stores the position of each
  character in the alien alphabet.
- Compare every adjacent pair of words.
- At the first differing character, compare their ranks.
- If all compared characters are equal, ensure the
  shorter word appears first.

Key Insight:
Instead of comparing characters alphabetically,
compare their positions in the custom alien alphabet.
The prefix case (e.g., "apple" before "app") must be
handled separately.
------------------------------------------------------------
*/
class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        int alienRank[26];
        for (int i = 0; i < order.size(); i++) {
            alienRank[order[i] - 'a'] = i; 
        }
        for (int i = 0; i < words.size() - 1; i++) {
            string w1 = words[i];
            string w2 = words[i + 1];
            
            bool sortedThisPair = false;
            for (int j = 0; j < w1.size() && j < w2.size(); j++) {
                
                int rank1 = alienRank[w1[j] - 'a'];
                int rank2 = alienRank[w2[j] - 'a'];
                
                if (rank1 < rank2) {
                    sortedThisPair = true;
                    break;
                } else if (rank1 > rank2) {
                    return false; 
                }

            }
            if (!sortedThisPair && w1.size() > w2.size()) {
                return false;
            }
        }
        return true;
    }
};