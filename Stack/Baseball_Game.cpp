/*
------------------------------------------------------------
Problem : Baseball Game (LeetCode 682)
Pattern : Stack

Time Complexity : O(N)
Space Complexity : O(N)

Idea:
- Use a stack to store all valid scores.
- Process each operation:
    - Number → Push the score onto the stack.
    - "C"    → Remove the most recent score.
    - "D"    → Push double the most recent score.
    - "+"    → Push the sum of the previous two scores.
- After processing all operations, sum every score in
  the stack.

Key Insight:
Each operation depends only on previously recorded scores,
and the most recent scores are needed first. This makes a
stack a natural data structure for the problem.

Example:
Operations:
5, 2, C, D, +

Stack progression:
5
5 → 2
5
5 → 10
5 → 10 → 15

Final Score = 30

------------------------------------------------------------
*/

class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> s;
        for (string op : operations) {
            
            if (op == "C") {
                s.pop();
                
            } else if (op == "D") {
                s.push(s.top() * 2);
                
            } else if (op == "+") {
                int top1 = s.top(); 
                s.pop();            
                int top2 = s.top(); 
                int newScore = top1 + top2;                 
                s.push(top1);    
                s.push(newScore);   
                
            } else {
                s.push(stoi(op));
            }
        }
        int totalSum = 0;
        while (!s.empty()) {
            totalSum += s.top();
            s.pop();
        }

        return totalSum;
    }
};