/*
------------------------------------------------------------
Problem : Jump Game VII (LeetCode 1871)
Pattern : Graph (BFS) + Greedy Window Optimization
Time Complexity : O(n)
Space Complexity : O(n)

Idea:
- Treat each reachable index as a node in a graph.
- Perform BFS starting from index 0.
- From each index, explore all positions in the range:
      [current + minJump, current + maxJump]
- Use 'farthest' to ensure every index is scanned
  only once, avoiding repeated work.
- Return true as soon as the last index is reached.

Key Insight:
Without the 'farthest' optimization, overlapping
jump ranges would make the algorithm O(n²).
Tracking the farthest scanned position reduces it
to O(n).
------------------------------------------------------------
*/

class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        if(s.back() == '1'){
            return false; 
        }

        queue<int> q;
        q.push(0); 
        
        int farthest = 0;
        
        while(!q.empty()) {
            int currentElement = q.front();
            q.pop();
            int start = max(currentElement + minJump, farthest + 1);
            int end = min(currentElement + maxJump, (int)s.length() - 1);
            for (int j = start; j <= end; j++) {
                if(s[j] == '0') { 
                    if(j == s.length() - 1){
                        return true;
                    }
                    q.push(j); 
                }
            }
            
            farthest = max(farthest, currentElement + maxJump);
        }
        
        return false;
    }
};