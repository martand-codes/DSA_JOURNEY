/*
------------------------------------------------------------
Problem : Contains Duplicate II (LeetCode 219)
Pattern : Hashing + Sliding Window

Time Complexity : O(N) Average
Space Complexity : O(K)

Idea:
- Maintain a sliding window containing at most K previous
  elements using an unordered_set.
- For every element, check whether it already exists in
  the current window.
- If it exists, a duplicate is found within distance K.
- Insert the current element into the window.
- Remove the element that falls outside the window.

Key Insight:
Only the previous K elements can form a valid nearby
duplicate with the current element, so maintaining a
sliding window avoids comparing the current element
with the entire array.
------------------------------------------------------------
*/

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> window;
        
        for (int i = 0; i < nums.size(); i++) {
            if (window.count(nums[i])) {
                return true;
            }
            window.insert(nums[i]);
            if (window.size() > k) {
                window.erase(nums[i - k]);
            }
        }
        
        return false;
    }
};