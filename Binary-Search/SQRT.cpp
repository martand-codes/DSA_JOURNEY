/*
------------------------------------------------------------
Problem : Sqrt(x) (LeetCode 69)
Pattern : Binary Search

Time Complexity : O(log N)
Space Complexity : O(1)

Idea:
- Search for the largest integer whose square is less than
  or equal to x.
- Maintain the search range [left, right].
- If mid * mid <= x:
    - mid is a valid answer.
    - Store it in ans and search for a larger value.
- Otherwise, mid is too large, so search the left half.

Key Insight:
We are not searching for x itself. We are finding the
largest integer `mid` satisfying:

    mid * mid <= x

Whenever a valid mid is found, we save it as the current
best answer and continue searching to the right.

`(long long)mid * mid` is used to prevent integer overflow
when calculating the square.

------------------------------------------------------------
*/

class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) return 0;
        int left = 1, right = x;
        int ans = 0;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if ((long long)mid * mid <= x) {
                ans = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        return ans;
    }
};