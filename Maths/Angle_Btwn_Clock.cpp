// Problem: Angle Between Hands of a Clock
// Pattern: Math / Simulation
// TC: O(1)
// SC: O(1)
//
// Idea:
// Minute hand moves 6 degrees per minute.
// Hour hand moves 30 degrees per hour
// and 0.5 degrees per minute.
// Compute the absolute difference
// and return the smaller angle.

class Solution {
public:
    double angleClock(int hour, int minutes) {
        
        double minute_angle = minutes * 6.0;
        
        double hour_angle = (hour % 12) * 30.0 + (minutes * 0.5);
        
        double diff = abs(hour_angle - minute_angle);
        return min(diff, 360.0 - diff);
    }
};