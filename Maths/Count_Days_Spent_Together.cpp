/*
------------------------------------------------------------
Problem : Count Days Spent Together (LeetCode 2409)
Pattern : Date Conversion + Interval Intersection

Time Complexity : O(1)
Space Complexity : O(1)

Idea:
- Convert each MM-DD date into its day number within
  a non-leap year using the dayConvertor() helper.
- Calculate the overlapping interval:
    overlapStart = max(aliceStart, bobStart)
    overlapEnd   = min(aliceEnd, bobEnd)
- If the intervals overlap, count both the start and
  end days inclusively.
- If there is no overlap, return 0.

Key Insight:
The common period begins on the later arrival date
and ends on the earlier departure date.

    Overlap = max(0, overlapEnd - overlapStart + 1)

The +1 is necessary because both arrival and departure
dates are inclusive.

Since the dates use a fixed, non-leap year and have
a constant number of months, the conversion and overlap
calculations take O(1) time.

------------------------------------------------------------
*/


class Solution {
    int dayConvertor(string date) {
        int monthDays[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int month = stoi(date.substr(0, 2));
        int day = stoi(date.substr(3, 2));
        
        int yearDays = 0;
        for (int i = 0; i < month - 1; ++i) {
            yearDays += monthDays[i];
        }
        
        yearDays += day;
        return yearDays;
    }

public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int aliceStart = dayConvertor(arriveAlice);
        int aliceEnd = dayConvertor(leaveAlice);
        int bobStart = dayConvertor(arriveBob);
        int bobEnd = dayConvertor(leaveBob);
        int overlapStart = max(aliceStart, bobStart);
        int overlapEnd = min(aliceEnd, bobEnd);
        return max(0, overlapEnd - overlapStart + 1);
    }
};