/*
------------------------------------------------------------
Problem : Maximum Product Subarray (LeetCode 152)
Pattern : Dynamic Programming (Kadane's Variation)

Time Complexity : O(N)
Space Complexity : O(1)

Idea:
- Track both the maximum and minimum product ending at
  the current position.
- The minimum is important because multiplying it by a
  negative number can produce the new maximum product.
- If the current number is negative, swap the maximum and
  minimum values before updating them.
- At every position, either start a new subarray with the
  current number or extend the previous subarray.

Key Insight:
A negative number can turn the smallest negative product
into the largest positive product. Therefore, both the
maximum and minimum product ending at each position must
be tracked.

------------------------------------------------------------
*/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int maxValue = nums[0];
        int minValue = nums[0];
        int result = maxValue;

        for(int i = 1; i < n; i++) {
            int currentNum = nums[i];
            if(currentNum < 0) { // For -ve Values
                swap(maxValue, minValue);
            }

            maxValue = max(currentNum, currentNum * maxValue);
            minValue = min(currentNum, currentNum * minValue);

            result = max(result, maxValue);
        }
        return result;
        
        
    }
};