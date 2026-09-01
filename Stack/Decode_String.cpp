/*
------------------------------------------------------------
Problem : Decode String (LeetCode 394)
Pattern : Stack / Nested Expression Parsing

Time Complexity  : O(N * K) in the worst case
Space Complexity : O(N)

Where:
    N = size of the encoded string
    K = amount of repetition / size of decoded output

Idea:
- The string can contain nested expressions such as:

      3[a2[c]]

- Whenever we encounter '[':
      1. Save the repetition count.
      2. Save the string constructed before '['.
      3. Reset both current count and current string so we
         can process the nested expression.

- Whenever we encounter ']':
      1. Retrieve the repetition count.
      2. Retrieve the string that existed before '['.
      3. Repeat the current decoded string that many times.
      4. Attach it to the previous string.

Two Stacks:

    countStack
        → Stores repetition counts.

    stringStack
        → Stores the string that existed before entering
          each '['.


Example:

    Input:
        3[a2[c]]

Process:

    '3'
        k = 3

    '['
        countStack  = [3]
        stringStack = [""]
        k = 0
        currentStr = ""

    'a'
        currentStr = "a"

    '2'
        k = 2

    '['
        countStack  = [3, 2]
        stringStack = ["", "a"]
        k = 0
        currentStr = ""

    'c'
        currentStr = "c"

    ']'
        repeatTimes = 2
        previous string = "a"

        "a" + ("c" × 2)
        = "acc"

        currentStr = "acc"

    ']'
        repeatTimes = 3
        previous string = ""

        "" + ("acc" × 3)
        = "accaccacc"


Important:

Multi-digit numbers are constructed using:

    k = k * 10 + (c - '0')

Example:

    "12[ab]"

    1 → k = 1
    2 → k = 12


Key Insight:

Every '[' creates a new nested state.

Every ']' finishes that nested state and combines it with
the state saved before '['.

Therefore:

    '[' → PUSH state
    ']' → POP state


The two stacks allow us to remember both:

    repetition count
    previous string

while processing arbitrarily nested expressions.

------------------------------------------------------------
*/

class Solution {
public:
    string decodeString(string s) {
        stack<int> countStack;
        stack<string> stringStack;
        string currentStr = "";
        int k = 0;
        
        for (char c : s) {
            if (isdigit(c)) {
                k = k * 10 + (c - '0');
            } 
            else if (c == '[') {
                countStack.push(k);
                stringStack.push(currentStr);

                k = 0;
                currentStr = "";
            } 
            else if (c == ']') {
                int repeatTimes = countStack.top();
                countStack.pop();
                
                string decodedString = stringStack.top();
                stringStack.pop();

                for (int i = 0; i < repeatTimes; ++i) {
                    decodedString += currentStr;
                }
                
                currentStr = decodedString;
            } 
            else {
                currentStr += c;
            }
        }
        
        return currentStr;
    }
};