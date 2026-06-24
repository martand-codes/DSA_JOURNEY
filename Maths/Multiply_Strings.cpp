// Problem: Multiply Strings
// Pattern: Math + Simulation
// TC: O(m * n)
// SC: O(m + n)
//
// Idea:
// Simulate elementary-school multiplication.
// Store intermediate results in an array.
// Handle carry using two positions:
// p1 = i + j
// p2 = i + j + 1
//
// Avoid converting strings into integers.

class Solution {
public:
    string multiply(string num1, string num2) {

        if (num1 == "0" || num2 == "0") return "0";
        
        int m = num1.length(), n = num2.length();

        vector<int> res(m + n, 0);

        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {

                int mul = (num1[i] - '0') * (num2[j] - '0');

                int p1 = i + j;
                int p2 = i + j + 1;

                int sum = mul + res[p2];
                

                res[p2] = sum % 10;
                
                res[p1] += sum / 10;
            }
        }
        

        string out = "";
        for (int num : res) {
           
            if (!(out.empty() && num == 0)) {
                out.push_back(num + '0');
            }
        }
        
        return out;
    }
};

