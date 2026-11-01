/*
------------------------------------------------------------
Problem : Largest Rectangle in Histogram (LeetCode #84)
Pattern : Monotonic Stack + Next Smaller Element + Greedy

Time Complexity : O(N)
Space Complexity : O(N)

Idea:
- Append a sentinel height of 0 to process all remaining bars.
- Maintain a stack of indices with monotonically increasing heights.
- Traverse the histogram from left to right.
- Whenever the current height is smaller than the height at
  the stack's top, pop that index and calculate its rectangle.
- The popped bar's height is the rectangle height.
- Calculate the width using the current index and the new
  stack top (previous smaller element).
- Update the maximum area.
- Push the current index onto the stack.

Key Insight:
- When a bar is popped, the current index is its first smaller
  element on the right.
- The new stack top is its first smaller element on the left.
- Therefore:
  width = rightBoundary - leftBoundary - 1.
- Each index is pushed and popped at most once, giving O(N) time.

------------------------------------------------------------
*/
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0); 
        vector<int> stack; 
        int max_area = 0;  
        for (int i = 0; i < heights.size(); i++) {
            while (!stack.empty() && heights[stack.back()] > heights[i]) {
                int height = heights[stack.back()];
                stack.pop_back();
                int width = stack.empty() ? i : i - stack.back() - 1;
                max_area = max(max_area, height * width);
            }
            stack.push_back(i);
        }
        return max_area;
    }
};