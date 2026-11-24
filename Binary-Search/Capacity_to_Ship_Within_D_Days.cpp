/*
------------------------------------------------------------
Problem : Capacity To Ship Packages Within D Days (LeetCode 1011)
Pattern : Binary Search on Answer / Monotonic Predicate /
          Greedy Simulation / Search Space Reduction

Time Complexity :
O(N * log(S - W + 1))

- N = Number of packages.
- S = Sum of all package weights.
- W = Maximum individual package weight.
- Binary search operates over the capacity range [W, S].
- Each binary search iteration traverses all N packages
  to calculate the number of days required.
- Therefore, the overall time complexity is
  O(N * log(S - W + 1)).

Space Complexity :
O(1)

- Only a constant number of variables are used.
- Shipping feasibility is checked using greedy simulation.
- No additional data structures are created.

Idea:
1. The problem asks for the minimum ship capacity required
   to transport all packages within the given number of days.

2. Instead of trying every possible capacity, apply
   Binary Search on Answer.

3. Establish the search space using two constraints:

       low = Maximum package weight
       high = Sum of all package weights

   - The ship must have capacity at least equal to the
     heaviest individual package.
   - The sum of all weights represents the maximum possible
     capacity, allowing all packages to be shipped in one day.

4. Initialize ans = high because shipping everything in
   one day is always feasible under the problem constraints.

5. Calculate the middle capacity:

       mid = low + (high - low) / 2

6. Check whether the ship can transport all packages
   within the given number of days using this capacity.

   Initialize:

       neededDays = 1
       currentLoad = 0

7. Traverse the packages in their original order.

   For every package weight w:

   - If currentLoad + w exceeds the current ship capacity:
       Increase neededDays by 1.
       Reset currentLoad to 0 because a new shipping day
       has started.

   - Add the current package weight to currentLoad.

       currentLoad += w

8. After processing all packages, compare neededDays
   with the allowed number of days:

   - If neededDays <= days:
       The current capacity is feasible.
       Store mid as a potential answer and search for
       a smaller capacity using high = mid - 1.

   - If neededDays > days:
       The current capacity is insufficient.
       Increase the minimum capacity using low = mid + 1.

9. Continue binary search until low exceeds high.

10. Return ans, which stores the minimum feasible
    shipping capacity.

Key Insight:
The feasibility of a shipping capacity follows a monotonic
property:

    If capacity C is sufficient,
    every capacity greater than C is also sufficient.

    If capacity C is insufficient,
    every capacity smaller than C is also insufficient.

This monotonic behavior makes Binary Search on Answer possible.

Why Greedy Simulation?
For a fixed capacity, loading packages in their given order
and filling each day as much as possible minimizes the
number of days required.

The moment adding another package exceeds the capacity,
we must start a new day because packages cannot be split
and their order cannot be changed.

Therefore, this greedy simulation correctly determines
whether a given capacity is feasible.

Why These Search Boundaries?

    Minimum Capacity = Maximum Individual Weight

A package cannot be divided across multiple days, so the
ship must accommodate the heaviest package.

    Maximum Capacity = Sum of All Package Weights

At this capacity, all packages can be shipped in one day.

Important Concepts:
- Binary Search on Answer: Search for the smallest capacity
  satisfying a feasibility condition.
- Monotonic Predicate: Increasing capacity can never
  increase the number of required shipping days.
- Greedy Simulation: Fill the current day until the next
  package would exceed the capacity.
- Order Preservation: Packages must be shipped in their
  original sequence.

Complexity Variables:
N = Number of packages.
S = Sum of all package weights.
W = Maximum individual package weight.

------------------------------------------------------------
*/

class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low = 0, high = 0;
        for (int w : weights) {
            low = max(low, w);
            high += w;
        }

        int ans = high;
        while (low <= high) {
            int mid = low + (high - low) / 2;

            int neededDays = 1;
            int currentLoad = 0;

            for (int w : weights) {
                if (currentLoad + w > mid) {
                    neededDays++;
                    currentLoad = 0;
                }
                currentLoad += w;
            }

            if (neededDays <= days) {
                ans = mid; 
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};