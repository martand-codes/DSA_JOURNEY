/*
------------------------------------------------------------
Problem : Maximum Frequency Stack (LeetCode 895)
Pattern : Stack + Hash Maps

Time Complexity:
    push() → O(1) average
    pop()  → O(1) average

Space Complexity:
    O(N)

Goal:
- Implement a stack that behaves differently from a normal
  stack.
- When popping, return the element with the highest
  frequency.
- If multiple elements have the same frequency, return the
  one that was pushed most recently.


Data Structures:

1. freq

    unordered_map<int, int> freq;

    Maps:

        value → current frequency

    Example:

        5 → 3
        7 → 2
        4 → 1


2. group

    unordered_map<int, stack<int>> group;

    Maps:

        frequency → stack of values that reached that
                     frequency

    Conceptually:

        group[1] → [5, 7, 4]
        group[2] → [5, 7]
        group[3] → [5]

    The top of each stack represents the most recently
    pushed element among values having that frequency.


3. maxfreq

    Stores the highest frequency currently present.

    This allows pop() to immediately access:

        group[maxfreq]

    without searching through all frequencies.


PUSH:

    int f = ++freq[val];

    Increase the value's frequency.

    maxfreq = max(maxfreq, f);

    Update the highest frequency if necessary.

    group[f].push(val);

    Store the value inside the stack corresponding to its
    new frequency.


POP:

    Start from:

        group[maxfreq]

    because we always need the most frequent value.

    The top element gives the most recently pushed value
    among all values with that frequency.

    After removing it:

        freq[val]--;

    If the highest-frequency stack becomes empty:

        maxfreq--;

    This works because the maximum frequency can decrease
    by at most one after a single pop.


Example:

    push(5)
    push(7)
    push(5)
    push(7)
    push(4)
    push(5)

Frequencies:

    5 → 3
    7 → 2
    4 → 1

Frequency groups:

    group[1] → [5, 7, 4]
    group[2] → [5, 7]
    group[3] → [5]

    maxfreq = 3


First pop():

    group[3].top() → 5

    Return 5.

    Frequency:

        5 → 2

    group[3] becomes empty.

    Therefore:

        maxfreq = 2


Second pop():

    group[2].top() → 7

    Return 7.

    Even though 5 and 7 may have the same frequency,
    7 is selected because it is the most recently pushed
    among the values at that frequency.


Key Insight:

A normal stack gives:

    Most Recently Used

This problem requires:

    Highest Frequency
        ↓
    Most Recently Used among ties

So we combine two ideas:

    Hash Map
        → Track frequency.

    Stack per frequency
        → Track recency within that frequency.


The crucial representation is:

    frequency → stack of values

This lets us answer both requirements in O(1) average time.

------------------------------------------------------------
*/



class FreqStack {
private:
    unordered_map<int, int> freq;       
    unordered_map<int, stack<int>> group;
    int maxfreq;                

public:
    FreqStack() {
        maxfreq = 0;
    }
    
    void push(int val) {
        int f = ++freq[val];
        maxfreq = max(maxfreq, f);
        group[f].push(val);
    }
    
    int pop() {
        int val = group[maxfreq].top();
        group[maxfreq].pop();
        
        freq[val]--;
        if (group[maxfreq].empty()) {
            maxfreq--;
        }
        
        return val;
    }
};

