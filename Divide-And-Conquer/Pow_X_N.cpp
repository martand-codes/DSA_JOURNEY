// Problem: Find Power of X^N
// Logic: Divide And Conquer
// TC: O(log n)
// SC: O(log n)


// Simple Recursion Approach:

// TC: O(n)
// SC: O(n)


class Solution {
public:
    double myPow(double x, int n) {

        // We have to multiply x like n times 
        
        // Base Case

        if (n == 0 ) {
            return 1;
        }
        
        // For Handling -ve Power
        if(n < 0){
            return 1 / myPow(x, -n);
        }

        // Recursion

        return x * myPow(x, n-1);
    }
};



// Using Divide and Conquer

// TC: O(log n)
// SC: O(log n)
class Solution {
public:
    double myPow(double x, long long n) { // Use long long to handle OverFlow!
        
        // Base Case: 
        
        if (n == 0) {
            return 1;
        }

        // Edge Case:

        if (n < 0) {
            return 1 / myPow(x, -n);
        }
        // Dividing

        double halfPow = myPow(x, n/2);
        double halfPowSqr = halfPow * halfPow;  // Use Double otherwise the Test Case of Decimal would fail

        // Conquering

        if (n % 2 != 0) {  // For Odd Power
            return x * halfPowSqr;
        }

        return halfPowSqr;
    }

};