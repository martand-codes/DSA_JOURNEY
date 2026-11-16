/*
------------------------------------------------------------
Problem : Digit Sum (LeetCode 2243)
Pattern : String / Simulation / String Manipulation /
          Group Processing

Time Complexity :
DigitSum : O(N * log_K(N))

Space Complexity : O(N)

Idea:
Repeatedly divide the string into consecutive groups of
size k and replace each group with the sum of its digits
until the resulting string length becomes less than or
equal to k.

- Continue processing while the string length exceeds k.
- Initialize an empty string next to store the transformed
  string for the current iteration.
- Traverse the string in consecutive groups of size k
  using the outer loop.
- Initialize sum to zero for every group.
- Use the inner loop to traverse the current group:
  - Ensure the index remains within the string bounds.
  - Convert each character into its corresponding digit
    using s[j] - '0'.
  - Accumulate the digit values into sum.
- Convert the calculated group sum into a string using
  to_string(sum).
- Append the group sum to next.
- After processing all groups, replace s with next.

Finally:
- Return s when its length becomes less than or equal
  to k.

Key Insight:
Each iteration transforms the string by replacing every
consecutive group of k digits with its digit sum.

The outer loop processes groups, while the inner loop
calculates the sum of digits within each group.

The resulting string becomes shorter after every
iteration, eventually satisfying the termination
condition s.length() <= k.

N represents the initial length of the string.
K represents the group size.

Each iteration processes all current characters,
requiring O(N) time for the first iteration.

The string length decreases approximately by a factor
of k in each iteration, resulting in O(log_K(N))
iterations for k > 1.

Therefore, the overall time complexity is
O(N * log_K(N)) for k > 1.

The auxiliary string next requires O(N) space in the
worst case, resulting in O(N) auxiliary space.

------------------------------------------------------------
*/

class Solution {
public:
    string digitSum(string s, int k) {
        while (s.length() > k) {
            string next = "";
            for (int i = 0; i < s.length(); i += k) {
                int sum = 0;
                for (int j = i; j < s.length() && j < i + k; j++) {
                    sum += s[j] - '0';
                }
                next += to_string(sum);
            }
            s = next;
        }
        return s;
    }
};