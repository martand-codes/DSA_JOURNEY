/*
------------------------------------------------------------
Problem : Implement Stack Using Queues (LeetCode 225)
Pattern : Queue / Stack

Time Complexity :
- push()  : O(N)
- pop()   : O(1)
- top()   : O(1)
- empty() : O(1)

Space Complexity : O(N)

Idea:
- Implement a Stack (LIFO) using only a Queue (FIFO).
- Use a single queue.
- Whenever a new element is pushed, rotate all the
  previous elements behind it.
- This makes the newly pushed element appear at the
  FRONT of the queue.
- Therefore, the front of the queue always represents
  the TOP of our simulated stack.

Example:

push(1):
    [1]

push(2):
    [1, 2]
    Rotate 1
    [2, 1]

push(3):
    [2, 1, 3]
    Rotate 2
    [1, 3, 2]
    Rotate 1
    [3, 2, 1]

Queue:
    FRONT → [3, 2, 1]

Simulated Stack:
    TOP → 3
           2
           1

Operations:
- push(x)  → Add x, then rotate the queue.
- pop()    → Remove the front element.
- top()    → Return the front element.
- empty()  → Check whether the queue is empty.

Key Insight:
A queue is FIFO, while a stack is LIFO.
By rotating the queue after every push, we force the
newest element to the front, making the queue behave
like a stack.

------------------------------------------------------------
*/

class MyStack {
private:
    queue<int> q;

public:
    MyStack() {}
    
    void push(int x) {
        q.push(x);
        // Rotating the queue
        for (int i = 0; i < q.size() - 1; ++i) {
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        int topElement = q.front();
        q.pop();
        return topElement;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};
