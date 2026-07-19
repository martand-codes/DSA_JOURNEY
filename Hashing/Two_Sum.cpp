/*
Problem : Two Sum (LeetCode 1)
Pattern : Hashing
Time Complexity : O(n)
Space Complexity : O(n)

Idea:
- Traverse the array once.
- For each element, compute the required complement:
      need = target - nums[i]
- If the complement already exists in the hash map,
  return both indices.
- Otherwise, store the current value and its index.

Key Insight:
A hash map allows constant-time lookup of previously
seen elements, reducing the brute-force O(n²)
solution to O(n).
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // Optimized Approach Using Hashing
        unordered_map<int, int>mp;
        int n = nums.size();
        for(int i = 0; i < n;i++){
            int need = target - nums[i];
            if(mp.find(need) != mp.end()){
                return {mp[need],i};
            }
            mp[nums[i]] = i;
        }
        // Brute Force
        // int n = nums.size();
        // for(int i = 0; i < n; i++){
           // for(int j = i+1; j<n; j++){
             //   if(nums[i] + nums[j] == target){
               //     return{i,j};
                // }
            // }
        // }
        return{};
        
    }
};