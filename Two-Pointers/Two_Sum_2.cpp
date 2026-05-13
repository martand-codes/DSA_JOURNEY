
// Problem: Two Sum II
// Pattern: Two Pointers
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        
        // We will solve it through 2 pointer Approach because it is sorted 

        // Simple:


        int start = 0 , end = numbers.size() -1;
        int currentSum = 0; // Defined currentSum or Reference Sum as 0

        // Let us make a vector for answer pair


        while(start < end) {
            currentSum = numbers[start] + numbers[end];
            if(currentSum == target) {
                return {start + 1, end + 1}; 
            } else if (currentSum > target) { // Simple: If Sum is bigger go to the next smaller element (Sorted Array!)
                end--;                
            }
            else {
                start++;
            }
        }
        return {};
    }
};