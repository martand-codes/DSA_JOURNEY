// Problem: Matchsticks to Square (LeetCode 473)
// Pattern: Backtracking + Pruning
// TC: Exponential (heavily pruned)
// SC: O(n)
//
// Idea:
// Sort matchsticks in descending order.
// Try placing each stick into one of the four sides.
// Skip placements that exceed the target.
// Backtrack if needed.
// Break when encountering an empty side to avoid symmetric states.

class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {
        if (matchsticks.size() < 3) {
            return false;
        }
        vector<int> sides(4, 0);
        int sum = 0;
        for(int i = 0; i < matchsticks.size(); i++) {
            sum += matchsticks[i];
        }
        if(sum % 4 != 0) {
            return false;
        }
        int target = sum / 4;
        sort(matchsticks.rbegin(), matchsticks.rend()); // To get better time also the maximum number should be entered first
        
        return helper(matchsticks, 0, sides, target);

    }

    bool helper(vector<int>& matchsticks, int index, vector<int>& sides, int target) {
        // Base Case:
        
        if (index == matchsticks.size()){  // Answer Case
            return true;
        }

        for(int i = 0; i < 4; i++) {
            if(sides[i] + matchsticks[index] <= target) {
                sides[i] += matchsticks[index];
                if(helper(matchsticks, index + 1, sides, target)) {
                    return true;
                }
                sides[i] -= matchsticks[index]; // BackTrack
            }

            if (sides[i] == 0) {
                break;
            }   
        }
        return false;
    }

};