/*
------------------------------------------------------------
Problem : Boats to Save People (LeetCode 881)
Pattern : Greedy / Sorting / Two Pointers

Time Complexity :
Sorting      : O(N log N)
Boat Pairing : O(N)
Overall      : O(N log N)

Space Complexity : O(log N) Auxiliary
                   (Sorting Stack Space)

Idea:
Minimize the number of rescue boats by pairing
the lightest and heaviest remaining passengers.

- Sort the people array in ascending order.
- Initialize left and right pointers to the
  lightest and heaviest remaining passengers.
- If their combined weight is within the limit,
  assign both passengers to the same boat.
- Otherwise, assign the heaviest passenger alone.
- Increment the boat count after every allocation.
- Continue until all passengers are assigned.

Key Insight:
The heaviest remaining passenger must be assigned
a boat in every iteration.

If the heaviest passenger can share a boat with
the lightest passenger, pairing them is optimal.
Otherwise, the heaviest passenger must travel alone.

Sorting enables greedy pairing, while two pointers
efficiently track the remaining passengers.

N represents the number of people.

------------------------------------------------------------
*/

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());    
        int left = 0;
        int right = people.size() - 1;
        int boats = 0;
        while (left <= right) {
            if (people[left] + people[right] <= limit) {
                left++; 
                right--; 
            } else {
                right--; 
            }
            boats++;
        }
        
        return boats;
    }
};