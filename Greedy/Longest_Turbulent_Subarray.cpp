/*
Problem : Longest Turbulent Subarray (LeetCode 978)
Pattern : Dynamic Programming (State Tracking)
Time Complexity : O(n)
Space Complexity : O(1)

Idea:
- Maintain two states:
    high -> longest turbulent subarray ending at i
            where arr[i] > arr[i-1]

    low  -> longest turbulent subarray ending at i
            where arr[i] < arr[i-1]

- If the current comparison is increasing,
  extend the previous decreasing sequence.

- If the current comparison is decreasing,
  extend the previous increasing sequence.

- Equal elements reset both states.

Key Insight:
A turbulent sequence alternates between
greater-than and less-than comparisons.

*/

class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        if (arr.size() == 1) {
            return 1;
        }
        // Kadane's
        int maxStreak = 1;
        int high = 1;
        int low = 1;

        // We are comparing From the Start so
        for(int i = 1; i < arr.size(); i++) {
            // If second element is bigger
            if(arr[i] > arr[i - 1]) {
              //  high++; // This takes to continous High !No Turbulence
              // Better
              high = low + 1;
              low = 1;
            }
            // If it's smaller
            else if(arr[i] < arr[i-1]) {
                // low++; // This takes to continous Low !No Turbulence
                low = high + 1;
                high = 1;
            }
            else {
                high = 1;
                low = 1;
            }
            maxStreak = max({maxStreak, high, low});
        }
        
        return maxStreak;

    }
};