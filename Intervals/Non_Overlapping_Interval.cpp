/*
------------------------------------------------------------
Problem : Non-overlapping Intervals (LeetCode 435)
Pattern : Intervals + Greedy

Time Complexity : O(N log N)
Space Complexity : O(1) auxiliary space

Idea:
- Sort intervals by their ending time.
- Keep the interval that finishes earliest.
- For every next interval:
    - If it overlaps with the previous selected interval,
      remove the current interval.
    - Otherwise, keep it and update the ending time.

Key Insight:
To maximize the number of non-overlapping intervals,
always keep the interval that ends earliest.
An earlier ending leaves the maximum possible room
for the remaining intervals.

Therefore, instead of directly choosing which intervals
to remove, greedily select the maximum number of
non-overlapping intervals and return:

    Total Intervals - Selected Intervals

------------------------------------------------------------
*/

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty()) return 0;
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        
        int removeCount = 0;
        int lastEndTime = intervals[0][1];
        
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] < lastEndTime) {
                removeCount++;
            } else {
                lastEndTime = intervals[i][1];
            }
        }
        
        return removeCount;
    }
};