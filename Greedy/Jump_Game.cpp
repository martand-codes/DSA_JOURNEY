/*
------------------------------------------------------------
Problem : Jump Game (LeetCode 55)
Pattern : Greedy
Time Complexity : O(n)
Space Complexity : O(1)

Idea:
- Maintain the farthest index that can be reached.
- If the current index is beyond the farthest reachable
  index, reaching the end is impossible.
- Otherwise, keep updating the farthest reachable index.
- If the farthest reachable index reaches the last
  position, return true.

Key Insight:
Only the farthest reachable position matters.
The exact sequence of jumps is irrelevant.

*/

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxReach = 0;
        
        for(int i = 0; i < nums.size(); i++) {
            // Index is anyway greater than our fuel then the result is not possible
            if(i > maxReach) {
                return false;
            }

            maxReach = max(maxReach, i + nums[i]); // We have to add the Index to the nums[i] because we have to check how much farther we can go with this much fuel
            if(maxReach >= nums.size()) {
                return true;
            }
        }
        return true;
    }
};