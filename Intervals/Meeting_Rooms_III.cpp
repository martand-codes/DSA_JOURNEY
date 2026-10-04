/*
------------------------------------------------------------
Problem : Meeting Rooms III (LeetCode 2402)
Pattern : Intervals + Greedy + Two Priority Queues

Time Complexity : O(N log N + M log N)
Space Complexity : O(N)

Idea:
- Sort meetings by their starting time.
- Maintain two min heaps:
    1. availableRooms:
       Stores room numbers that are currently free.
       Smallest room number is given priority.
    2. busyRooms:
       Stores {endingTime, roomNumber}.
       The room that becomes free earliest is given priority.
- Before scheduling each meeting, move all rooms whose
  meetings have ended into availableRooms.
- If a room is available, assign the smallest numbered room.
- Otherwise, take the room that becomes available earliest
  and delay the meeting until that room becomes free.
- Track how many meetings each room handles.

Key Insight:
There are TWO different priorities:
- Among free rooms → choose the smallest room number.
- Among busy rooms → choose the room with the earliest
  ending time, breaking ties by smallest room number.

When no room is available, the meeting keeps its original
duration, so its new ending time becomes:

    earliestAvailableTime + meetingDuration

The room with the highest meeting count is the answer.
Ties are automatically resolved in favor of the smaller
room number by scanning from 0 to N-1.

------------------------------------------------------------
*/


class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());

        priority_queue<int, vector<int>, greater<int>> availableRooms;
        for (int i = 0; i < n; ++i) {
            availableRooms.push(i);
        }

        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> busyRooms;
        vector<int> meetingCount(n, 0);

        for (const auto& meeting : meetings) {
            long long start = meeting[0];
            long long end = meeting[1];
            long long duration = end - start;

            while (!busyRooms.empty() && busyRooms.top().first <= start) {
                availableRooms.push(busyRooms.top().second);
                busyRooms.pop();
            }

            if (!availableRooms.empty()) {
                int room = availableRooms.top();
                availableRooms.pop();
                busyRooms.push({end, room});
                meetingCount[room]++;
            } else {
                auto [availableTime, room] = busyRooms.top();
                busyRooms.pop();
                busyRooms.push({availableTime + duration, room});
                meetingCount[room]++;
            }
        }

        int maxMeetings = 0;
        int bestRoom = 0;
        for (int i = 0; i < n; ++i) {
            if (meetingCount[i] > maxMeetings) {
                maxMeetings = meetingCount[i];
                bestRoom = i;
            }
        }

        return bestRoom;
    }
};