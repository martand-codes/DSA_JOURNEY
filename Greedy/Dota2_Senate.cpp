/*
Problem : Dota2 Senate (LeetCode 649)
Pattern : Queue Simulation
Time Complexity : O(n)
Space Complexity : O(n)

Idea:
- Store the indices of Radiant and Dire senators in
  separate queues.
- Compare the front indices.
- The senator with the smaller index acts first and
  bans the opponent.
- The surviving senator is reinserted into the queue
  with index + n, representing participation in the
  next round.
- Continue until one queue becomes empty.

Key Insight:
Adding n to the winning senator's index naturally
simulates the circular order of voting without using
a circular array.
*/
class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> rad, dir;
        int n = senate.length();
        for (int i = 0; i < n; ++i) {
            if (senate[i] == 'R') {
                rad.push(i);
            } else {
                dir.push(i);
            }
        }
        while (!rad.empty() && !dir.empty()) {
            int r_idx = rad.front();
            rad.pop();
            
            int d_idx = dir.front();
            dir.pop();
            if (r_idx < d_idx) {
                rad.push(r_idx + n);
            } else {
                dir.push(d_idx + n);
            }
        }
        return rad.empty() ? "Dire" : "Radiant";
    }
};