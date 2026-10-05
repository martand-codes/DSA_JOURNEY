/*
------------------------------------------------------------
Problem : Longest Consecutive Sequence (LeetCode 128)
Pattern : Hashing + Sequence Detection

Time Complexity : O(N) average
Space Complexity : O(N)

Idea:
- Insert all numbers into an unordered_set for O(1)
  average-time lookup.
- For each number, check whether num - 1 exists.
- If it does not exist, the current number is the start
  of a consecutive sequence.
- Starting from that number, keep checking num + 1 and
  count the length of the sequence.
- Track the maximum sequence length.

Key Insight:
Only start counting from the beginning of a sequence.

If:

    num - 1 does not exist

then num must be the smallest element of its sequence.
This prevents repeatedly traversing the same sequence and
allows the overall algorithm to run in O(N) average time.

------------------------------------------------------------
*/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(), nums.end());
        int longestStreak = 0;

        for (int num : numSet) {
            // Check if it's the start of a sequence
            if (numSet.find(num - 1) == numSet.end()) {
                int currentNum = num;
                int currentStreak = 1;

                while (numSet.find(currentNum + 1) != numSet.end()) {
                    currentNum++;
                    currentStreak++;
                }

                longestStreak = max(longestStreak, currentStreak);
            }
        }

        return longestStreak;
    }
};