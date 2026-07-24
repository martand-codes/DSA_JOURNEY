/*
------------------------------------------------------------
Problem : Partition Labels (LeetCode 763)
Pattern : Greedy

Time Complexity : O(N)
Space Complexity : O(1)

Idea:
- Record the last occurrence of every character.
- Traverse the string while maintaining the farthest last
  occurrence among characters seen so far.
- When the current index reaches that farthest position,
  close the current partition.

Key Insight:
A partition cannot end until every character inside it has
its final occurrence within that partition.
------------------------------------------------------------
*/

class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> lastPosition(26, 0);

        for(int i = 0; i < s.length(); i++) {
            lastPosition[s[i] - 'a'] = i;
        }
        vector<int> result;
        int startChar = 0;
        int endChar = 0;

        for(int i = 0; i < s.length(); i++) {
            endChar = max(endChar, lastPosition[s[i] - 'a']);

            if(i == endChar) {
                result.push_back(endChar - startChar + 1);
                startChar = i + 1;
            }
        }
        return result;
    }
};