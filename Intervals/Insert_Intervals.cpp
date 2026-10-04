/*
------------------------------------------------------------
Problem : Insert Interval (LeetCode 57)
Pattern : Intervals / Greedy

Time Complexity : O(N)
Space Complexity : O(N)

Idea:
- Traverse the sorted intervals in three phases:
    1. Add intervals that end before newInterval starts.
    2. Merge every interval that overlaps with newInterval.
    3. Add all remaining intervals after the merged interval.
- During the merge phase, expand newInterval by taking the
  minimum starting point and maximum ending point.

Key Insight:
Because the intervals are already sorted, every interval
falls into one of three categories: completely before the
new interval, overlapping with it, or completely after it.
This allows the entire problem to be solved in a single
left-to-right traversal.

------------------------------------------------------------
*/


class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> result;
        int i = 0;
        int n = intervals.size();
        
        while (i < n && intervals[i][1] < newInterval[0]) {
            result.push_back(intervals[i]);
            i++;
        }
        
        while (i < n && intervals[i][0] <= newInterval[1]) {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }
        result.push_back(newInterval);
        
        while (i < n) {
            result.push_back(intervals[i]);
            i++;
        }
        
        return result;
    }
};