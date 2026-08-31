/*
------------------------------------------------------------
Problem : Evaluate Reverse Polish Notation (LeetCode 150)
Pattern : Stack

Time Complexity : O(N)
Space Complexity : O(N)

Idea:
- Use a stack to store operands.
- Process each token from left to right.

For every token:
    - Number → push it onto the stack.
    - Operator → pop the two most recent operands,
                 perform the operation, and push the result
                 back onto the stack.

Important:
For an operator, the FIRST value popped is the RIGHT operand,
and the SECOND value popped is the LEFT operand.

Example:

Tokens:
    ["2", "1", "+", "3", "*"]

Step 1:
    2 → stack = [2]

Step 2:
    1 → stack = [2, 1]

Step 3:
    +
    right = 1
    left  = 2
    2 + 1 = 3

    stack = [3]

Step 4:
    3 → stack = [3, 3]

Step 5:
    *
    right = 3
    left  = 3
    3 * 3 = 9

    stack = [9]

Final Answer:
    9

Important Operand Order:

    left - right
    left / right

NOT:

    right - left
    right / left

Key Insight:
Reverse Polish Notation places the operator AFTER its
operands. A stack naturally stores the operands until an
operator tells us to combine the two most recent values.

Operations:
    Number   → push
    Operator → pop two → calculate → push result

------------------------------------------------------------
*/

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;

        for(int i = 0; i < tokens.size(); i++) {
            
            if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/"){
                int right = s.top();
                s.pop();

                int left = s.top();
                s.pop();

                if(tokens[i] == "+") {
                    s.push(left + right);
                } else if(tokens[i] == "-") {
                    s.push(left - right);
                } else if(tokens[i] == "*") {
                    s.push(left * right);
                } else if(tokens[i] == "/") {
                    s.push(left / right);
                } 
            }
            else {
                    s.push(stoi(tokens[i]));
                }
        }

            return s.top();
    }
    
};