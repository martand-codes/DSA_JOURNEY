/* Initial Code
class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        stack<int> s;
         for(int i = 0; i < position.size(); i++) {
            int sumCheck = 0;
            for(int j = 0; j < speed.size(); j++) {
                if(position.size() && speed.size() == 1) {
                    s.push(1);
                }
                else if(position[i] + speed[j] == target) {
                    s.push(position[i]);
                }

                position[i] + speed[j] = sumCheck;
                s.push(sumCheck);
                sumCheck = s.top();

                if(position[i + 1] + speed[i + 1] == sumcheck) {
                    s.push(sumCheck);
                } else  {
                    s.pop();
                }
            }
         }
         return s.size() - 1;
    }
};
*/

/*
------------------------------------------------------------
Problem : Car Fleet (LeetCode 853)
Pattern : Monotonic Stack / Greedy

Time Complexity  : O(N log N)
Space Complexity : O(N)

Idea:
- Each car has a position and a speed.
- First combine them into {position, speed}.
- Sort cars by position so that cars closer to the target
  appear later in the array.
- Process cars from closest to the target to farthest.

For every car, calculate its time to reach the target:

    time = (target - position) / speed

A car can catch the fleet in front of it if its arrival time
is less than or equal to the fleet's arrival time.

Therefore:

    time <= fleet.top()
        → Current car joins the existing fleet.

    time > fleet.top()
        → Current car cannot catch the fleet.
        → It creates a new fleet.

Example:

    target = 12

    position = [10, 8, 5]
    speed    = [2, 4, 1]

Arrival times:

    position 10:
        (12 - 10) / 2 = 1

    position 8:
        (12 - 8) / 4 = 1

    position 5:
        (12 - 5) / 1 = 7

Process from closest to target:

    Car 10:
        fleet = [1]

    Car 8:
        time = 1
        1 <= 1
        → joins existing fleet

    Car 5:
        time = 7
        7 > 1
        → creates a new fleet

Answer:

    2 fleets

Important:
We process from right to left after sorting because the car
closest to the target determines the fleet immediately ahead
of the current car.

The stack stores the arrival time of each fleet.

Why the comparison is strictly greater:

    time > fleet.top()

If the times are equal, the cars reach the target together,
so they belong to the SAME fleet.

Complexity:

    Sorting:
        O(N log N)

    Stack traversal:
        O(N)

    Overall:
        O(N log N)

    Space:
        O(N)

Key Insight:
Don't track the physical movement of every car.

Instead, calculate when each car would reach the target.

A car with an earlier/equal arrival time can catch the fleet
ahead and therefore becomes part of that fleet.

------------------------------------------------------------
*/

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int, int>> cars(n);
        
        for(int i = 0; i < n; i++) {
            cars[i] = {position[i], speed[i]};
        }
        sort(cars.begin(), cars.end()); 
        
        stack<double> fleet;
        for(int i = n - 1; i >= 0; i--) {
            
            double time = (double)(target - cars[i].first) / cars[i].second;
            if(fleet.empty() || time > fleet.top()) {
                fleet.push(time); 
            }
        }
        
        return fleet.size();
    }
};