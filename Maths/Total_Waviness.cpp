// Problem: Total Waviness
// Pattern: Math
// TC: O((num2 - num1 + 1) * d)
// SC: O(1)

class Solution {
public:
    
    int totalWaviness(int num1, int num2) {
        int total_waviness = 0;
        
        for (int i = num1; i <= num2; ++i) {
            int temp = i;
            int digits[10]; // Large enough to hold any 32-bit integer's digits
            int idx = 0;
            
            // Extract digits (they will be stored in reverse order)
            while (temp > 0) {
                digits[idx++] = temp % 10;
                temp /= 10;
            }
            
            // Check for peaks and valleys
            // (Reversed digit order doesn't affect symmetric neighbor checks)
            for (int j = 1; j < idx - 1; ++j) {
                if (digits[j] > digits[j-1] && digits[j] > digits[j+1]) {
                    total_waviness++;
                } else if (digits[j] < digits[j-1] && digits[j] < digits[j+1]) {
                    total_waviness++;
                }
            }
        }
        
        return total_waviness;
    }
};