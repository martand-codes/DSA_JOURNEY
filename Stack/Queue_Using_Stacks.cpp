/*
------------------------------------------------------------
Problem : Implement Queue Using Stacks (LeetCode 232)
Pattern : Stack / Queue

Time Complexity :
- push()  : O(1)
- pop()   : O(1) amortized
- peek()  : O(1) amortized
- empty() : O(1)

Space Complexity : O(N)

Idea:
- Implement a Queue (FIFO) using two Stacks (LIFO).
- Use two stacks:
    1. inputStack  → stores newly pushed elements.
    2. outputStack → provides the front of the queue.

- New elements are always pushed into inputStack.
- When pop() or peek() is required:
    - If outputStack is empty, transfer every element
      from inputStack to outputStack.
    - This reverses the order of the elements.
    - The oldest element then appears at the top of
      outputStack.

Example:

push(1), push(2), push(3)

inputStack:
    TOP
     ↓
    [3]
    [2]
    [1]

outputStack:
    empty

Transfer:

inputStack              outputStack
    [3]                     [1] ← TOP
    [2]          →          [2]
    [1]                     [3]

Now:
    peek() → 1
    pop()  → 1

Key Insight:
A queue requires FIFO (First In, First Out), while a stack
provides LIFO (Last In, First Out).

Using two stacks reverses the order of elements, allowing
the oldest element to appear at the top of outputStack.

The transfer is performed only when outputStack is empty.
This gives O(1) amortized complexity for pop() and peek().

------------------------------------------------------------
*/

class MyQueue {
private:
    stack<int> inputStack;
    stack<int> outputStack;

    // Helper to transfer elements from inputStack to outputStack when needed
    void transfer() {
        if (outputStack.empty()) {
            while (!inputStack.empty()) {
                outputStack.push(inputStack.top());
                inputStack.pop();
            }
        }
    }

public:
    MyQueue() {}
    
    void push(int x) {
        inputStack.push(x);
    }
    
    int pop() {
        transfer();
        int frontElement = outputStack.top();
        outputStack.pop();
        return frontElement;
    }
    
    int peek() {
        transfer();
        return outputStack.top();
    }
    
    bool empty() {
        return inputStack.empty() && outputStack.empty();
    }
};
