/*
------------------------------------------------------------
Problem : Merge Triplets to Form Target Triplet (LeetCode 1899)
Pattern : Greedy

Time Complexity : O(N)
Space Complexity : O(1)

Idea:
- Ignore any triplet that exceeds the target in any position.
- For every valid triplet, check whether it contributes each target value.
- If every coordinate of the target can be contributed by at least one
  valid triplet, the target can be formed.

Key Insight:
Only triplets that are component-wise less than or equal to the target
can participate in the merge. After filtering them, independently verify
that each target coordinate appears.
------------------------------------------------------------
*/

class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        bool found0 = false;
        bool found1 = false;
        bool found2 = false;
        
        for (const auto& t : triplets) {
            if (t[0] <= target[0] && t[1] <= target[1] && t[2] <= target[2]) {
                if (t[0] == target[0]) found0 = true;
                if (t[1] == target[1]) found1 = true;
                if (t[2] == target[2]) found2 = true;
            }
        }
        
        return found0 && found1 && found2;
    }
};