/*
------------------------------------------------------------
Problem : Subarray Sum Equals K (LeetCode #560)
Pattern : Prefix Sum + Hashing + Frequency Map

Time Complexity : O(N) average
Space Complexity : O(N)

Idea:
- Maintain a running prefix sum while traversing the array.
- Store the frequency of every prefix sum in an unordered_map.
- For each element, calculate currentSum - k.
- If this value exists in the map, its frequency represents
  the number of subarrays ending at the current index with sum k.
- Add that frequency to the total count.
- Update the frequency of the current prefix sum.

Key Insight:
- If prefixSum[j] - prefixSum[i] = k,
  then the subarray (i+1 ... j) has sum k.
- Therefore, for every current prefix sum, search for
  currentSum - k in the frequency map.
- Initialize counter[0] = 1 to handle subarrays
  whose sum equals k from the beginning of the array.

------------------------------------------------------------
*/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> counter;
        // Base case
        counter[0] = 1;
        int currentSum = 0;
        int totalSubarrays = 0;
        for (int num : nums) {
            currentSum += num;  
            if (counter.find(currentSum - k) != counter.end()) {
                totalSubarrays += counter[currentSum - k];
            }
            counter[currentSum]++;
        }
        return totalSubarrays;
    }
};