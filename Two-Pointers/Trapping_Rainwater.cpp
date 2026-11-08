/*
------------------------------------------------------------
Problem : Trapping Rain Water (LeetCode 42)
Pattern : Two Pointers / Greedy / Prefix Maximums /
          Space Optimization

Time Complexity :
Trap : O(N)

Space Complexity : O(1)

Idea:
Calculate the total trapped rainwater using two pointers
and maintain the maximum heights encountered from
both directions.

- Initialize left and right pointers at the two ends
  of the height array.
- Maintain leftMax and rightMax to track the maximum
  heights encountered from their respective sides.
- Compare the heights at the left and right pointers.
- If the left height is smaller or equal:
  - Update leftMax if a new maximum is encountered.
  - Otherwise, calculate trapped water using
    leftMax - height[left].
  - Move the left pointer forward.
- Otherwise:
  - Update rightMax if a new maximum is encountered.
  - Otherwise, calculate trapped water using
    rightMax - height[right].
  - Move the right pointer backward.
- Accumulate the trapped water until both pointers
  converge.

Key Insight:
The water trapped above a position depends on the
minimum of its left and right maximum heights.

When height[left] <= height[right], the left side
determines the trapped water at the current left
position because a sufficiently tall right boundary
already exists.

Similarly, when height[right] < height[left],
the right side determines the trapped water.

This eliminates the need for separate prefix and
suffix maximum arrays.

N represents the number of elements in the height array.

The algorithm processes every element at most once
using constant auxiliary space.

------------------------------------------------------------
*/

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int l = 0, r = n - 1;
        int leftMax = 0, rightMax = 0;
        int water = 0;

        while(l < r) {
            if(height[l] <= height[r]) {
                if(height[l] >= leftMax)
                    leftMax = height[l];
                else
                    water += leftMax - height[l];
                l++;
            } else {
                if(height[r] >= rightMax)
                    rightMax = height[r];
                else
                    water += rightMax - height[r];
                r--;
            }
        }
        return water;
    }
};


        
  
