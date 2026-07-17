/*
Problem : Maximum Subarray (LeetCode 53)
Algorithm : Kadane's Algorithm
Pattern : Dynamic Programming / Greedy
Time Complexity : O(n)
Space Complexity : O(1)

Idea:
- Traverse the array while maintaining the maximum
  subarray sum ending at the current index.
- At each element, decide whether to:
    1. Extend the previous subarray, or
    2. Start a new subarray from the current element.
- Keep track of the overall maximum sum.

Transition:
currSum = max(nums[i], currSum + nums[i])

Key Insight:
If extending the previous subarray is worse than
starting fresh, begin a new subarray.
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int currSum = 0;
        int maxSum = INT_MIN;  // For handling -ve cases
        for(int i = 0; i < nums.size(); i++){
            // Greedy Choice
            currSum = max(nums[i], currSum + nums[i]);
            maxSum = max(currSum, maxSum);
        }
        return maxSum;

    }
};