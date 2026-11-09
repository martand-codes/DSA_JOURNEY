/*
------------------------------------------------------------
Problem : Two Sum II - Input Array Is Sorted (LeetCode 167)
Pattern : Two Pointers (Opposite Direction)

Time Complexity : O(N)
Space Complexity : O(1)

Idea:
- Place one pointer at the beginning and another at
  the end of the sorted array.
- Compute the current sum.
- If the sum is too small, move the left pointer
  right to increase the sum.
- If the sum is too large, move the right pointer
  left to decrease the sum.
- Continue until the target sum is found.

Key Insight:
The sorted order allows one pointer movement to
deterministically increase or decrease the current
sum, eliminating the need for hashing.
------------------------------------------------------------
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        int start = 0;;
        int end = n - 1;

        while(start < end) {
            if(numbers[start] + numbers[end] == target) {
                return{start + 1, end + 1};
            } else if(numbers[start] + numbers[end] > target) {
                end--;
            } else {
                start++;
            }
        }
        return{};
    }
};