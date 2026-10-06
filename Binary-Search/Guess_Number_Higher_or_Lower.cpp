
/*
------------------------------------------------------------
Problem : Guess Number Higher or Lower (LeetCode 374)
Pattern : Binary Search

Time Complexity : O(log N)
Space Complexity : O(1)

Idea:
- The secret number lies somewhere in the range [1, n].
- Use binary search to repeatedly check the middle value.
- The `guess()` API tells us whether the secret number is:
    - Equal to mid
    - Smaller than mid
    - Greater than mid
- Eliminate half of the search space based on the result.

Key Insight:
The `guess()` result directly tells us which half of the
search space contains the secret number.

    guess(mid) == 0  → mid is the answer
    guess(mid) < 0   → secret number < mid
    guess(mid) > 0   → secret number > mid

Therefore, just like normal binary search, each iteration
reduces the search space by roughly half.

------------------------------------------------------------
*/

class Solution {
public:
    int guessNumber(int n) {
        int left = 1, right = n;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int res = guess(mid);
            
            if (res == 0) {
                return mid;
            } else if (res < 0) {
                right = mid - 1; 
            } else {
                left = mid + 1;  
            }
        }
        
        return -1;
    }
};