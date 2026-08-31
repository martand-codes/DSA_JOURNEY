/*
------------------------------------------------------------
Problem : Daily Temperatures (LeetCode 739)
Pattern : Monotonic Stack / Dynamic Programming

Approach 1:
    Monotonic Decreasing Stack

Time Complexity : O(N)
Space Complexity : O(N)

Idea:
- Store INDICES of days whose warmer temperature has not
  been found yet.
- The stack maintains temperatures in decreasing order.
- When the current temperature is greater than the
  temperature at the index on top of the stack:
      → We have found the warmer day for that index.
      → Calculate the number of days between them.
      → Pop that index.
- Continue popping while the current temperature is warmer.
- Finally, push the current day's index onto the stack.

Example:

Temperatures:
    [73, 74, 75, 71, 72]

Process:

    73 → stack = [0]

    74 → 74 > 73
         days[0] = 1
         stack = [1]

    75 → 75 > 74
         days[1] = 1
         stack = [2]

    71 → 71 < 75
         stack = [2, 3]

    72 → 72 > 71
         days[3] = 1
         72 < 75
         stack = [2, 4]

Final:
    [1, 1, 0, 1, 0]

Key Insight:
The stack contains unresolved days.

When a warmer temperature arrives, it resolves one or
multiple previous days at once.

Each index is:
    - pushed onto the stack once
    - popped from the stack at most once

Therefore, although there is a while loop inside the for
loop, the total work is O(N), not O(N²).


------------------------------------------------------------
Approach 2:
    Dynamic Programming + Jumping

Time Complexity : O(N)
Space Complexity : O(N)

Idea:
- Traverse the temperatures from right to left.
- `days[i]` stores the number of days until a warmer
  temperature.
- If the immediate next day is not warmer, use its already
  calculated answer to jump directly to another candidate
  day.

Example:

    temperatures[i] = 71
    nextDay = i + 1

If:
    temperatures[nextDay] <= temperatures[i]

then instead of checking every day individually:

    nextDay += days[nextDay]

This uses previously calculated DP information to skip
days that cannot be the answer.

Important:
If `days[nextDay] == 0`, that position has no warmer
temperature ahead, so there is no point continuing through
that path.

Key Insight:
The DP solution avoids repeatedly checking temperatures by
reusing answers that were calculated for later positions.

Both approaches achieve:

    Time  → O(N)
    Space → O(N)

The Monotonic Stack approach is the more important general
pattern to recognize because it applies to many
"next greater element" problems.

------------------------------------------------------------
*/

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> s;
   
        vector<int> days(temperatures.size(), 0);

        for(int i = 0; i < temperatures.size(); i++) {
            while(!s.empty() && temperatures[i] > temperatures[s.top()]) {
                int pastTempIdx = s.top();
                s.pop();

                days[pastTempIdx] = i - pastTempIdx;
            }
            s.push(i);
        }
        
        return days;
    } 
};


class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        
        // This will hold our DP answers
        vector<int> days(n, 0);
        
        // Start from the second to last day and walk backwards
        for (int i = n - 2; i >= 0; i--) {
            int nextDay = i + 1;
            
            // Keep looping as long as the next day is cooler or equal
            while (temperatures[nextDay] <= temperatures[i]) {
                
                // If the cooler day's answer is 0, it never found a warmer day.
                // That means we won't find one either! Dead end.
                if (days[nextDay] == 0) {
                    nextDay = -1; // Mark as dead end
                    break;
                }
                
                // DP JUMP: Fast-forward to the next known warmer day!
                nextDay += days[nextDay];
            }
            
            // If we didn't hit a dead end, record how far we jumped
            if (nextDay != -1) {
                days[i] = nextDay - i;
            }
        }
        
        return days;
    } 
};