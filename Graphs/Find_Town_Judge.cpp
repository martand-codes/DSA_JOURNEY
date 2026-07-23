/*
------------------------------------------------------------
Problem : Find the Town Judge (LeetCode 997)
Pattern : Graph (In-degree / Out-degree Counting)
Time Complexity : O(n + m)
Space Complexity : O(n)

Idea:
- Every person starts with score 0.
- If someone trusts another person, decrease their score.
- Increase the trusted person's score.
- The judge trusts nobody and is trusted by everyone,
  giving them a final score of n - 1.

Key Insight:
Instead of maintaining separate indegree and outdegree
arrays, combine both into a single score array:
score = indegree - outdegree.
------------------------------------------------------------
*/

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        // Base Case:
        if(n == 1 && trust.empty()) {
            return 1;
        }

        vector<int> trustScore(n + 1, 0);

        for(int i = 0; i < trust.size(); i++) {
            int trusting = trust[i][0];
            int trusted = trust[i][1];

            trustScore[trusting]--;
            trustScore[trusted]++;
        }

        for(int i = 1; i <= n; i++) {
            if(trustScore[i] == n - 1 ) {
                return i;
            }
        }
        return -1;
    }
};