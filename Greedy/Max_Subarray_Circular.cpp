/*
Problem : Maximum Sum Circular Subarray (LeetCode 918)
Algorithm : Kadane's Algorithm
Pattern : Dynamic Programming / Greedy
Time Complexity : O(n)
Space Complexity : O(1)

Idea:
- Compute the maximum subarray sum using Kadane's Algorithm.
- Compute the minimum subarray sum using a mirrored Kadane.
- The maximum circular subarray sum equals:
      Total Sum - Minimum Subarray Sum
- Handle the special case where all elements are negative.
- Return the maximum of the normal and circular subarray sums.

Key Insight:
A circular maximum subarray is obtained by excluding the
minimum contiguous subarray from the total array sum.
*/

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int totalSum = 0;

        // Since it's circular Array we Need Minimum and Maximum using kadane's

        // Kadane's Algorithm
        int currentSum = 0;
        int maximumSum = INT_MIN;

        // For Minimum
        int currentMinSum = 0;
        int minimumSum = INT_MAX;

        for(int i = 0;i < nums.size(); i++) {
            totalSum += nums[i];
            currentSum = max(nums[i], currentSum + nums[i]);
            maximumSum = max(maximumSum, currentSum);

            currentMinSum = min(nums[i], currentMinSum + nums[i]);
            minimumSum = min(minimumSum, currentMinSum);

            
        }
        // Edge Case: For All -ve Numbers
        if (maximumSum < 0) {
                return maximumSum;
        }
        int answer = max(maximumSum, totalSum - minimumSum);
        return answer;
    }
};