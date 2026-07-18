/*
Problem : Gas Station (LeetCode 134)
Pattern : Greedy
Time Complexity : O(n)
Space Complexity : O(1)

Idea:
- Compute the total gas and total cost.
- If total gas is less than total cost,
  completing the circuit is impossible.
- Traverse the stations while maintaining the
  current fuel in the tank.
- If the tank becomes negative, reset the tank
  and choose the next station as the new starting
  candidate.

Key Insight:
If starting from station 'start' cannot reach
station 'i + 1', then no station between
'start' and 'i' can be the answer.
*/

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        // Defining the gas and costs
        int totalGas = 0;
        int totalCost = 0;
        
        // Kadane's
        int currentTank = 0;
        int startingStation = 0;
        
        for (int i = 0; i < gas.size(); i++) {
            
            totalGas += gas[i];
            totalCost += cost[i];
            
            // Simple Math: Current resource = existing - cost
            currentTank += (gas[i] - cost[i]);
            
            // Greedy
            if (currentTank < 0) {
                startingStation = i + 1; // The index we are at we can't go anywhere so increase the index
                currentTank = 0; // Resetting
            }
        }
        // Base Case
        if (totalGas < totalCost) {
            return -1;
        }
        return startingStation;
    }
};