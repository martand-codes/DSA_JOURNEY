/*
------------------------------------------------------------
Problem : Add Binary (LeetCode 67)
Pattern : String Simulation

Time Complexity : O(max(M, N))
Space Complexity : O(max(M, N))

Idea:
- Traverse both binary strings from right to left.
- Add corresponding bits along with the carry.
- Append the current binary digit (sum % 2).
- Update the carry (sum / 2).
- Reverse the constructed string to obtain the final answer.

Key Insight:
Binary addition follows the same process as decimal
addition. The only difference is that each digit is
either 0 or 1, so every position contributes a carry
of at most 1.
------------------------------------------------------------
*/

class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.length() - 1;      
        int j = b.length() - 1;    
        int carry = 0;               
        string answer = "";          
        while (i >= 0 || j >= 0 || carry > 0) {
            int sum = carry;
            if (i >= 0) {
                sum += a[i] - '0';  
                i--;
            }
            if (j >= 0) {
                sum += b[j] - '0'; 
                j--;
            }
            answer += to_string(sum % 2);
            carry = sum / 2;
        }
        reverse(answer.begin(), answer.end());
        return answer;
    }
};