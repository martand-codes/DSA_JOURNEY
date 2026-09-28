/*
------------------------------------------------------------
Problem : Product of Array Except Self (LeetCode 238)
Pattern : Prefix Product + Suffix Product

Time Complexity : O(N)
Space Complexity : O(N)

Idea:
- For every index i, the answer is the product of all
  elements to the left of i multiplied by the product of
  all elements to the right of i.
- leftProduct[i] stores the product of all elements before i.
- rightProduct[i] stores the product of all elements after i.
- Multiply both values to obtain the final answer.

Key Insight:
The product except self can be split into two independent
parts:
    Product of elements before i
    ×
    Product of elements after i

By precomputing prefix and suffix products, we avoid
using division and handle zero values naturally.

------------------------------------------------------------
*/


class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();

        vector<int> leftProduct(n), rightProduct(n), answer(n);
        leftProduct[0] = 1;
        rightProduct[n-1] = 1;

        for( int i = n-2; i >= 0; i--){  
            rightProduct[i] = rightProduct[i+1] * nums[i+1];
        }
        for( int i = 1; i < n; i++){ 
            leftProduct[i] = leftProduct[i-1] *  nums[i-1];
        }
        // For answer 
        for (int i = 0; i < n; i++){
             answer[i] = leftProduct[i] * rightProduct[i];
        }
        
        return answer;

        
    }
};