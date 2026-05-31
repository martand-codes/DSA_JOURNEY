// Problem: Destroying Asteroids
// Pattern: Greedy + Sorting
// TC: O(n log n)
// SC: O(1)

class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        // Sort asteroids from smallest to largest
        sort(asteroids.begin(), asteroids.end());
        
        // Use long long to prevent integer overflow during addition
        long long current_mass = mass;
        
        for (int asteroid : asteroids) {
            if (current_mass >= asteroid) {
                // Absorb the asteroid
                current_mass += asteroid;
            } else {
                // Planet is destroyed
                return false;
            }
        }
        
        return true;
    }
};