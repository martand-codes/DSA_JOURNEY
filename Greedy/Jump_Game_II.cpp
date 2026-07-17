/*
Problem : Jump Game II (LeetCode 45)
Pattern : Greedy (Range Expansion)
Time Complexity : O(n)
Space Complexity : O(1)

Idea:
- Treat each jump as covering a range of indices.
- While scanning the current range, compute the farthest
  reachable index.
- When the current range ends, make one jump and extend
  the range to the farthest reachable index.
- Repeat until the last index is reachable.

Key Insight:
Within a jump's range, always choose the farthest
possible reach for the next jump.
*/
class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size() <= 1) {
            return 0; // We can't do any jump if the size is this
        }
        int jumps = 0;
        int farthest = 0;
        int immidiateEnd = 0;
    
        // We don't need to traverse till the end
        for(int i = 0; i < nums.size() - 1; i++) {
            // Greedy
            farthest = max(farthest, i + nums[i]);
            if(i == immidiateEnd) {
                jumps++; // After Jumping to the Immidiate this is our Farthest
                immidiateEnd = farthest;

                if(immidiateEnd >= nums.size() - 1) {
                    break;
                }
            }
        }
        return jumps;
    }
};