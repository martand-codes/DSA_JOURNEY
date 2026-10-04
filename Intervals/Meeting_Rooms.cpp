/*
------------------------------------------------------------
Problem : Meeting Rooms (LeetCode 252)
Pattern : Intervals + Sorting

Time Complexity : O(N log N)
Space Complexity : O(1) auxiliary space

Idea:
- Sort all meetings by their starting time.
- Compare each meeting with the previous meeting.
- If the current meeting starts before the previous
  meeting ends, the two meetings overlap.
- Therefore, one person cannot attend both meetings.

Key Insight:
After sorting by start time, we only need to check
adjacent intervals. If any two consecutive meetings
overlap, attending all meetings is impossible.

Condition:
    current.start < previous.end  → Overlap

If:
    current.start >= previous.end → No overlap

------------------------------------------------------------
*/


class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const Interval& a, const Interval& b) {
            return a.start < b.start;
        });
        
        for (size_t i = 1; i < intervals.size(); ++i) {
            if (intervals[i].start < intervals[i - 1].end) {
                return false;
            }
        }
        return true;
    }
};