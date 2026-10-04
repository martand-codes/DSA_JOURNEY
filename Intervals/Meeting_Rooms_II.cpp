/*
------------------------------------------------------------
Problem : Meeting Rooms II (LeetCode 253)
Pattern : Intervals + Greedy + Min Heap

Time Complexity : O(N log N)
Space Complexity : O(N)

Idea:
- Sort all meetings by their starting time.
- Maintain a min heap containing the ending times
  of meetings currently occupying each room.
- For every meeting:
    - If the earliest-ending meeting has already ended
      before the current meeting starts, reuse that room.
    - Otherwise, allocate a new room.
- The size of the heap represents the number of rooms
  currently required.

Key Insight:
The minimum heap always gives us the room that becomes
available earliest.

If:
    interval.start >= minHeap.top()

we can reuse that room.

Otherwise, the current meeting overlaps with every
currently active meeting, so a new room is required.

------------------------------------------------------------
*/


class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        if (intervals.empty()) {
            return 0;
        }

        sort(intervals.begin(), intervals.end(), [](const Interval& a, const Interval& b) {
            return a.start < b.start;
        });

        priority_queue<int, vector<int>, greater<int>> minHeap;

        for (const auto& interval : intervals) {
            if (!minHeap.empty() && interval.start >= minHeap.top()) {
                minHeap.pop();
            }
            minHeap.push(interval.end);
        }

        return minHeap.size();
    }
};