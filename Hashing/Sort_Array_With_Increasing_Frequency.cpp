/*
------------------------------------------------------------
Problem : Sort Array by Increasing Frequency (LeetCode 1636)
Pattern : Hashing + Sorting + Custom Comparator

Time Complexity : O(N log N)
Space Complexity : O(N)

Idea:
Use an unordered_map to calculate the frequency of every
element in the array.

Sort the original array using a custom comparator:
- Elements with lower frequency appear first.
- If two elements have equal frequency, the larger
  element appears first.

The comparator accesses the frequency map to determine
the ordering between any two elements.

Key Insight:
A custom comparator allows sorting elements according
to multiple conditions.

Frequency determines the primary ordering, while the
value itself determines the secondary ordering when
frequencies are equal.
------------------------------------------------------------
*/

class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }
        sort(nums.begin(), nums.end(), [&freq](int a, int b) {
            if (freq[a] == freq[b]) {
                return a > b; 
            }
            return freq[a] < freq[b];
        });
        
        return nums;
    }
};