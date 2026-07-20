/*
Problem : Hand of Straights (LeetCode 846)
Pattern : Greedy + Hashing + Sorting
Time Complexity : O(n log n)
Space Complexity : O(n)

Idea:
- Count the frequency of each card.
- Sort the cards.
- Iterate from the smallest card.
- If the current card is unused, greedily form a
  consecutive group of size groupSize.
- If any required card is unavailable, return false.

Key Insight:
The smallest remaining card must always start a new group.
Sorting guarantees that no smaller card is left unused,
making the greedy strategy correct.
*/

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if (n % groupSize != 0) {
            return false;
        }
        unordered_map<int, int> count;
        for (int card : hand) {
            count[card]++;
        }
        sort(hand.begin(), hand.end());
        
        for (int card : hand) {
            if (count[card] == 0) {
                continue;
            }
            for (int i = 0; i < groupSize; ++i) {
                if (count[card + i] == 0) {
                    return false; 
                }
                count[card + i]--;
            }
        }
        
        return true;
    }
};
