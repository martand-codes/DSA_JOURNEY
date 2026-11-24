/*
------------------------------------------------------------
Problem : Koko Eating Bananas (LeetCode 875)
Pattern : Binary Search on Answer / Monotonic Predicate /
          Greedy Feasibility Check

Time Complexity :
O(N * log K)

- N = Number of piles.
- K = Maximum number of bananas in a single pile.
- Binary search performs O(log K) iterations.
- Each iteration traverses all N piles to calculate
  the total hours required at the current eating speed.
- Therefore, total time complexity is O(N * log K).

Space Complexity :
O(1)

- Only a constant number of variables are used.
- No additional data structures are created.

Idea:
1. The problem asks for the minimum integer eating speed
   at which Koko can finish all banana piles within h hours.

2. Instead of trying every possible eating speed, apply
   Binary Search on Answer.

3. Define the search space:

       low = 1
       high = maximum pile size

   - Minimum possible speed is 1 banana per hour.
   - Maximum pile size is sufficient to finish every pile
     in one hour.

4. Calculate the middle eating speed:

       mid = low + (high - low) / 2

5. Check whether Koko can finish all piles at speed mid.

   For every pile p, calculate the hours required:

       hours = (p + mid - 1) / mid

   This is an integer ceiling division that calculates
   ceil(p / mid) without using floating-point arithmetic.

6. Accumulate the hours required for all piles:

       hours += (p + mid - 1) / mid

7. Compare the total required hours with the available
   time h:

   - If hours <= h:
       The current speed is feasible.
       Store mid as a potential answer and search for
       a smaller speed by updating high = mid - 1.

   - If hours > h:
       The current speed is insufficient.
       Increase the minimum speed by updating low = mid + 1.

8. Continue until low exceeds high.

9. Return ans, which stores the minimum feasible
   eating speed found during binary search.

Key Insight:
The feasibility of an eating speed follows a monotonic
property:

    If speed K is sufficient,
    every speed greater than K is also sufficient.

    If speed K is insufficient,
    every speed smaller than K is also insufficient.

This monotonic behavior allows Binary Search on Answer.

Instead of searching for an element in a sorted array,
we search for the smallest value that satisfies a
feasibility condition.

Why Ceiling Division?

    ceil(p / mid) = (p + mid - 1) / mid

Koko cannot carry partially eaten bananas into the next
hour, so every pile requires a whole number of hours.

For example:

    p = 10, mid = 3

    hours = (10 + 3 - 1) / 3
          = 12 / 3
          = 4

Why long long for hours?
The total hours accumulated across all piles can exceed
the range of a 32-bit integer in sufficiently large inputs.
Using long long prevents potential integer overflow.

Why ans = high?
The maximum pile size is guaranteed to be a feasible
eating speed under the standard problem constraints,
so it provides an initial valid answer.

Complexity Variables:
N = Number of banana piles.
K = Maximum number of bananas in any single pile.

------------------------------------------------------------
*/

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        int ans = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            long long hours = 0;

            for (int p : piles) {
                hours += (p + mid - 1) / mid;
            }

            if (hours <= h) {
                ans = mid;    
                high = mid - 1;
            } else {
                low = mid + 1;   
            }
        }

        return ans;
    }
};