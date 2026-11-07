/*
------------------------------------------------------------
Problem : Bulls and Cows (LeetCode 299)
Pattern : Hashing / Frequency Counting

Time Complexity : O(N)
Space Complexity : O(1)

Idea:
Maintain two frequency arrays of size 10 to track digit
frequencies in secret and guess respectively.

Traverse both strings simultaneously:
- If characters match at the same index, increment bulls.
- Otherwise, increment the frequency of the secret digit
  and the guessed digit in their respective arrays.

After processing all positions, calculate cows by summing
the minimum frequency of each digit across both arrays.

Return the result in the format "xAyB", where x represents
bulls and y represents cows.

Key Insight:
Bulls are exact positional matches and must be excluded
from the frequency counting.

Cows are digits that exist in both strings at different
positions. Taking the minimum frequency for each digit
ensures that duplicates are counted correctly without
double-counting bulls.
------------------------------------------------------------
*/

class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls = 0;
        int cows = 0;
        vector<int> secret_counts(10, 0);
        vector<int> guess_counts(10, 0);
        for (int i = 0; i < secret.length(); i++) {
            if (secret[i] == guess[i]) {
                bulls++;
            } else {
                secret_counts[secret[i] - '0']++;
                guess_counts[guess[i] - '0']++;
            }
        }
        for (int i = 0; i < 10; i++) {
            cows += min(secret_counts[i], guess_counts[i]);
        }
        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};