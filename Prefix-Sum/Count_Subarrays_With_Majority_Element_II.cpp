// Problem: Count Subarrays With Majority Element II 
// Pattern: Prefix Sum + Balance Transformation + Frequency Counting
// TC: O(n)
// SC: O(n)
//
// Idea:
// Treat:
// target -> +1
// other elements -> -1
// Maintain a running balance (prefix sum)
// Use a frequency array with an offset to count
// previous balances efficiently.
// Count all subarrays where the target is the majority element

class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> freq(2 * n + 2, 0);
        int offset = n;
        freq[offset] = 1;
        
        int count_smaller = 0;
        long long ans = 0;
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