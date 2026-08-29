/*
------------------------------------------------------------
Problem : Valid Parentheses (LeetCode 20)
Pattern : Stack

Time Complexity : O(N)
Space Complexity : O(N)

Idea:
- Use a stack to keep track of opening brackets.
- When an opening bracket is encountered, push it.
- When a closing bracket is encountered:
    1. Check if the stack is empty.
    2. Check whether the closing bracket matches the
       opening bracket at the top of the stack.
    3. If it matches, pop the opening bracket.
    4. Otherwise, return false.

At the end:
- If the stack is empty → all brackets were matched.
- If the stack is not empty → unmatched opening brackets
  remain, so return false.

Example:
    "{[()]}"

    {       → push
    { [     → push
    { [ (   → push
    { [     → ')' matches '(' → pop
    {       → ']' matches '[' → pop
    empty   → '}' matches '{' → pop

Key Insight:
A stack follows LIFO (Last In, First Out), which perfectly
matches the requirement that the most recently opened bracket
must be the first one to close.

------------------------------------------------------------
*/


class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        
        for (char c : s) {
            if (c == '(' || c == '{' || c == '[') {
                st.push(c);
            } 
            else {
                if (st.empty()) {
                    return false;
                } 
            
                char top = st.top();
                if ((c == ')' && top == '(') || 
                    (c == '}' && top == '{') || 
                    (c == ']' && top == '[')) {
                    st.pop(); 
                } else {
                    return false; 
                }
            }
        }
        return st.empty();
    }
};