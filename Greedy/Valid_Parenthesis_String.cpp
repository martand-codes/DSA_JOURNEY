/*
------------------------------------------------------------
Problem : Valid Parenthesis String (LeetCode 678)
Pattern : Greedy + Range of Possible Balance

Time Complexity : O(N)
Space Complexity : O(1)

Idea:
- Maintain two values:
    low  → minimum possible number of unmatched '('
    high → maximum possible number of unmatched '('
- For '(':
    low++ and high++
- For ')':
    low-- and high--
- For '*':
    '*' can act as '(', ')' or empty:
        low--  → treat '*' as ')'
        high++ → treat '*' as '('
- Keep low >= 0 because the balance cannot be negative.
- If high < 0 at any point, there are too many ')' characters
  and the string can never be valid.

Key Insight:
Instead of deciding what every '*' represents immediately,
track the entire possible range of balances.

    [low, high] = all possible unmatched '(' counts

If high becomes negative, even the most optimistic
interpretation cannot make the string valid.

At the end, low == 0 means there exists at least one
interpretation of '*' that produces a valid parenthesis string.

------------------------------------------------------------
*/

class Solution {
public:
    bool checkValidString(string s) {
        int low = 0, high = 0;
        for (char c : s) {
            if (c == '(') {
                low++;
                high++;
            } else if (c == ')') {
                low = max(0, low - 1);
                high--;
            } else {
                low = max(0, low - 1);
                high++;
            }
            if (high < 0) {
                return false;
            }
        }
        return low == 0;
    }
};