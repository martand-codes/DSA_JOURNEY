// Problem: Count Subarrays With Majority Element I 
// Pattern: Prefix Sum + Balance Transformation + Frequency Counting
// TC: O(n)
// SC: O(n)
//
// Idea:
// Convert:
// target -> +1
// other elements -> -1
//
// Maintain a running balance (prefix sum).
// Use a frequency array to count previous balances
// that form valid majority subarrays.

class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> freq(2 * n + 2, 0);
        int offset = n;
        freq[offset] = 1;
        
        int count_smaller = 0;
        int ans = 0;
        int curr_sum = 0;
        
        for (int num : nums) {
            if (num == target) {
                count_smaller += freq[curr_sum + offset];
                curr_sum++;
            } else {
                curr_sum--;
                count_smaller -= freq[curr_sum + offset];
            }
            
            ans += count_smaller;
            freq[curr_sum + offset]++;
        }
        
        return ans;
    }
};