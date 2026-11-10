/*
------------------------------------------------------------
Problem : Climbing Stairs with Minimum Costs (LeetCode  stair-cost variant)
Pattern : Dynamic Programming / Space Optimization /
          Rolling Variables / Fixed-Window DP

Time Complexity :
ClimbStairs : O(N)

Space Complexity : O(1)

Idea:
Calculate the minimum total cost to reach the top
using three previous DP states and constant space.

The algorithm maintains:
- a : Minimum cost from three positions behind.
- b : Minimum cost from two positions behind.
- c : Minimum cost from the immediately preceding position.
- d : Minimum cost for the current position.

For every position i:
- Calculate the minimum cost of reaching the current
  position from the previous three possible positions.
- Add costs[i] to account for the current stair.
- Update the rolling variables to move the DP window
  forward by one position.

The transition is:

d = costs[i] + min(
    c + 1,
    b + 4,
    a + 9
)

The three transitions represent different jump sizes
with their corresponding additional movement costs.

Key Insight:
Only the previous three DP states are required to
calculate the current state.

Instead of maintaining a complete DP array, rolling
variables preserve the necessary states and reduce
auxiliary space to O(1).

N represents the number of stairs.

The algorithm processes each stair exactly once,
resulting in linear time and constant auxiliary space.

------------------------------------------------------------
*/

class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        int a = 0, b = 0, c = 0, d;
        for (int i = 0; i < n; i++) {
            d = costs[i] + min({
                c + 1,
                b + 4,
                a + 9
            });
            a = b;
            b = c;
            c = d;
        }
        return d;
    }
};