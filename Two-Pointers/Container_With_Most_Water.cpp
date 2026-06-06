// Problem: Container With Most Water
// Pattern: Two Pointers
// TC: O(n)
// SC: O(1)

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