/*
------------------------------------------------------------
Problem : Matrix Chain Multiplication (MCM)
Pattern : Recursion / Partition DP

Time Complexity : Exponential
Space Complexity : O(N) — Recursion Stack

Idea:
- Given matrices represented by their dimensions in arr,
  recursively find the minimum cost to multiply matrices
  from index i to j.
- Try every possible partition k between i and j.
- Recursively calculate the minimum multiplication cost
  for the left and right partitions.
- Add the cost of multiplying the two resulting matrices:
      arr[i - 1] * arr[k] * arr[j]
- Take the minimum cost among all possible partitions.

Key Insight:
Matrix multiplication is associative, so the order of
multiplication can be changed. Every possible partition
represents a different parenthesization, and we choose
the one with minimum multiplication cost.

Base Case:
If i == j, there is only one matrix, so no multiplication
is required and the cost is 0.

------------------------------------------------------------
*/


// MCM with Recursion

int mcmRecursion(vector<int> &arr, int i, int j) {
    if(i == j) {
        return 0;
    }

    int ans = INT_MAX;

    for(int k = i; k < j; k++) {
        // (i , k)
        int cost1 = mcmRecursion(arr, i, k);

        // (k + 1, j)
        int cost2 = mcmRecursion(arr, k + 1, j);

        // Current Partition Cost
        int currentCost = cost1 + cost2 +(arr[i - 1] * arr[k] * arr[j]);
        ans = min(ans, currentCost);
    }
    return ans;
}