/*
------------------------------------------------------------
Problem : Min Stack (LeetCode 155)
Pattern : Stack

Time Complexity :
- push()   : O(1)
- pop()    : O(1)
- top()    : O(1)
- getMin() : O(1)

Space Complexity : O(N)

Idea:
- Use two stacks:
    1. s        → stores all values normally.
    2. minStack → stores the minimum values needed to
                  determine the current minimum in O(1).

- Whenever a new value is pushed:
    - Push it into the normal stack.
    - If it is less than or equal to the current minimum,
      also push it into minStack.

- Whenever a value is popped:
    - If the value being removed is the current minimum,
      also pop it from minStack.
    - Then pop it from the normal stack.

Example:

push(5)
    s:        [5]
    minStack: [5]

push(3)
    s:        [3, 5]
    minStack: [3, 5]

push(7)
    s:        [7, 3, 5]
    minStack: [3, 5]

push(2)
    s:        [2, 7, 3, 5]
    minStack: [2, 3, 5]

getMin() → 2

After pop():

    s:        [7, 3, 5]
    minStack: [3, 5]

getMin() → 3

Important:
Use <= instead of < when pushing into minStack.

This handles duplicate minimum values correctly.

Example:
    push(2)
    push(2)
    pop()

The second 2 must remain as the minimum after the first
2 is removed.

Key Insight:
The normal stack tells us the current top element, while
minStack remembers the minimum value at every relevant
stage.

Therefore getMin() never needs to scan the stack.

------------------------------------------------------------
*/


class MinStack {
private:
    stack<int> s;        
    stack<int> minStack;  

public:
    MinStack() {}
    
    void push(int val) {
        s.push(val);
        if (minStack.empty() || val <= minStack.top()) {
            minStack.push(val);
        }
    }
    
    void pop() {
        if (s.top() == minStack.top()) {
            minStack.pop();
        }
        s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return minStack.top();
    }
};
