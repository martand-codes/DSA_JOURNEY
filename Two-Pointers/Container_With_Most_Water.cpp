/*
------------------------------------------------------------
Problem : Container With Most Water (LeetCode 11)
Pattern : Two Pointers / Greedy

Time Complexity : O(N)
Space Complexity : O(1)

Idea:
Use two pointers starting at opposite ends of the height
array. The width of the container is the distance between
the pointers, and its height is the minimum of the two
boundary heights.

Calculate the area at every step and update max_area.

Move the pointer corresponding to the smaller height inward
because the smaller boundary limits the current area.

Continue until both pointers meet.

Key Insight:
Moving the taller boundary cannot produce a larger area
while keeping the shorter boundary fixed, because the
width decreases and the limiting height cannot increase.

Therefore, always moving the shorter boundary allows us
to eliminate impossible candidates while preserving the
possibility of finding a larger area.
------------------------------------------------------------
*/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int max_area = 0;
        
        while (left < right) {
            // Calculate the current area
            int current_height = min(height[left], height[right]);
            int current_width = right - left;
            int current_area = current_height * current_width;
            
            // Update max_area if we found a larger one
            max_area = max(max_area, current_area);
            
            // Move the pointer pointing to the shorter line inward
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }
        
        return max_area;
    }
};