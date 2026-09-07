/*
------------------------------------------------------------
Problem : 0/1 Knapsack
Pattern : Dynamic Programming / Recursion

Time Complexity : O(2^N)
Space Complexity : O(N)

Idea:
For every item that fits, make two choices:
1. Include the item and reduce the remaining capacity.
2. Exclude the item and keep the capacity unchanged.

If the item does not fit, it must be excluded.

Key Insight:
Each state is defined by the remaining capacity W and
the number of available items n. The optimal answer is
the maximum of including or excluding the current item.
------------------------------------------------------------
*/


// Knapsack using Recursion

int knapSackRecursion(const vector<int>& values,
                      const vector<int>& weights,
                      int W,
                      int n) {

    // Base Case
    if (W <= 0 || n == 0) {
        return 0;
    }

    int val = values[n - 1];
    int weigh = weights[n - 1];

    if (weigh <= W) {

        // Include
        int inclusion =
            knapSackRecursion(values, weights, W - weigh, n - 1) + val;

        // Exclude
        int exclusion =
            knapSackRecursion(values, weights, W, n - 1);

        return max(inclusion, exclusion);

    } else {

        // Only Exclude
        return knapSackRecursion(values, weights, W, n - 1);
    }
}


/*
------------------------------------------------------------
Problem : 0/1 Knapsack
Pattern : Dynamic Programming / Memoization (Top-Down)

Time Complexity : O(N × W)
Space Complexity : O(N × W)

Idea:
Use recursion to explore include/exclude choices and store
the result of every state in a 2D DP table.

dp[n][W] represents the maximum value obtainable using the
first n items with capacity W.

Key Insight:
Memoization prevents recalculating the same (n, W) state.
Each state is solved at most once.
------------------------------------------------------------
*/

// Knapsack using Memoization

int knapSackMemoization(const vector<int>& values,
                      const vector<int>& weights,
                      int W,
                      int n, vector<vector<int>>& dp) {

    // Base Case
    if (W <= 0 || n == 0) {
        return 0;
    }

    // Memoization
    if(dp[n][W] != -1) {
        return dp[n][W];
    }

    int val = values[n - 1];
    int weigh = weights[n - 1];

    if (weigh <= W) {

        // Include
        int inclusion =
            knapSackMemoization(values, weights, W - weigh, n - 1, dp) + val;

        // Exclude
        int exclusion =
            knapSackMemoization(values, weights, W, n - 1, dp);

        dp[n][W] = max(inclusion, exclusion);

    } else {

        // Only Exclude
        dp[n][W] = knapSackRecursion(values, weights, W, n - 1, dp);
    }
    return dp[n][W]; 
}


/*
------------------------------------------------------------
Problem : 0/1 Knapsack
Pattern : Dynamic Programming / Tabulation (Bottom-Up)

Time Complexity : O(N × W)
Space Complexity : O(N × W)

Idea:
Build a 2D DP table where dp[i][j] represents the maximum
value obtainable using the first i items with capacity j.

For every item, choose between including it or excluding it
when the item's weight fits the current capacity.

Key Insight:
Each table cell depends only on the previous row:
dp[i][j] = max(include, exclude).
The table eliminates recursion and computes every state once.
------------------------------------------------------------
*/

// knapsack using tabulation

int knapSackTabulation (vector<int> values, vector<int> weights, int W, int n) {
    
    // Defining the Table
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for(int  i = 1; i < n + 1; i++) {
        for(int j = 1; j < W + 1; j++) {
            int itemWeight = weights[i - 1];
            int itemValue = values[i - 1];

            if(itemWeight <= j) { // Not W because we are taking on capacity in each cell which will eventually lead to W

                int inclusion = itemValue + dp[i - 1][j - itemWeight];
                int exclusion = dp[i - 1][j]; // Taking the previous value as it's excluded
                dp[i][j] = max(inclusion, exclusion);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[i][j];
}



/*
------------------------------------------------------------
Problem : Unbounded Knapsack
Pattern : Dynamic Programming / Tabulation (Bottom-Up)

Time Complexity : O(N × W)
Space Complexity : O(N × W)

Idea:
Build a 2D DP table where dp[i][j] represents the maximum
value obtainable using the first i items with capacity j.

For every item that fits, choose between including or
excluding it.

Key Insight:
Unlike 0/1 Knapsack, including an item keeps the same row:
dp[i][j - itemWeight]. This allows the same item to be
selected multiple times.
------------------------------------------------------------
*/


// Unbounded Knapsack

int unboundedKnapSack (vector<int> values, vector<int> weights, int W, int n) {
    
    // Defining the Table
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for(int  i = 1; i < n + 1; i++) {
        for(int j = 1; j < W + 1; j++) {
            int itemWeight = weights[i - 1];
            int itemValue = values[i - 1];

            if(itemWeight <= j) { // Not W because we are taking on capacity in each cell which will eventually lead to W

                int inclusion = itemValue + dp[i][j - itemWeight]; // Unlimited Quantity We can take again and again and again
                int exclusion = dp[i - 1][j]; // Taking the previous value as it's excluded
                dp[i][j] = max(inclusion, exclusion);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[i][j];
}