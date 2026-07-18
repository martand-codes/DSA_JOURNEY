/*
Problem : Merge Intervals (LeetCode 56)
Pattern : Greedy + Sorting
Time Complexity : O(n log n)
Space Complexity : O(n)

Idea:
- Sort intervals based on their starting points.
- Initialize the merged list with the first interval.
- For every remaining interval:
    • If it overlaps with the last merged interval,
      extend the ending point.
    • Otherwise, add it as a new interval.
- Return the merged intervals.

Key Insight:
Sorting ensures that all potential overlapping
intervals appear consecutively, allowing a
single linear scan after sorting.
*/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // Base case: If there is only 1 interval, nothing to merge.
        if (intervals.size() <= 1) {
            return intervals;
        } 
        
        //  Greedy: Sorting from the start 
        sort(intervals.begin(), intervals.end());
        
        vector<vector<int>> merged;
        
        // Pushing the first Index
        merged.push_back(intervals[0]);
        
        for (int i = 1; i < intervals.size(); i++) {
            vector<int> current = intervals[i];
            vector<int>& lastMerged = merged.back(); // Getting the last interval
            if (current[0] <= lastMerged[1]) { // For Overlapping
                lastMerged[1] = max(lastMerged[1], current[1]);
            } else { // Not Overlapping
                merged.push_back(current);
            }
        }
        
        return merged;
    }
};