// Problem: Maximum Element After Decreasing and Rearranging (LeetCode 1846)
// Pattern: Greedy + Sorting
// TC: O(n log n)
// SC: O(1) (excluding sorting)
//
// Idea:
// 1. Sort the array.
// 2. Force the first element to be 1.
// 3. Traverse the array.
// 4. If the current element is more than previous + 1,
//    reduce it to previous + 1.
// 5. The last element becomes the maximum possible value.

class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        
        arr[0] = 1;
        
        for (int i = 1; i < arr.size(); ++i) {
            if (arr[i] > arr[i - 1] + 1) {
                arr[i] = arr[i - 1] + 1;
            }
        }
        
        return arr.back();
    }
};