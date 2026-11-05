/*
Problem: Find the Distance Value Between Two Arrays
LeetCode: 1385
Topic: Sorting + Binary Search
Difficulty: Easy

Approach:
1. Sort arr2 to enable binary search.
2. For each element in arr1, find the first element in arr2
   greater than or equal to (num - d) using lower_bound.
3. If this element exists and is <= (num + d), num is invalid.
4. Otherwise, increment the valid distance count.

Time Complexity: O(m log m + n log m)
Space Complexity: O(1) auxiliary space

Key Concepts:
- lower_bound()
- Sorted array
- Binary search
- Range exclusion
*/

class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        sort(arr2.begin(), arr2.end());
        int valid_count = 0;
        for (int num : arr1) {
            auto it = lower_bound(arr2.begin(), arr2.end(), num - d);

            if (it != arr2.end() && *it <= num + d) {
                continue;
            }
            valid_count++;
        }
        return valid_count;
    }
};