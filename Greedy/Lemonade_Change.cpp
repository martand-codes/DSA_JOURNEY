/*

Problem : Lemonade Change (LeetCode 860)
Pattern : Greedy
Time Complexity : O(n)
Space Complexity : O(1)

Idea:
- Keep track of the number of $5 and $10 bills.
- For each customer:
    • $5  → collect it.
    • $10 → give one $5 as change.
    • $20 → always prefer giving $10 + $5.
      If not possible, give three $5 bills.
- If change cannot be provided at any point,
  return false.

Key Greedy Insight:
Always preserve as many $5 bills as possible,
since they are required to make change for
future customers.

*/
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int tens = 0;
        int fives = 0;

        for(int i = 0; i < bills.size(); i++){
            int currentBill = bills[i];

            // For 5$
            if(currentBill == 5) {
                fives++; // Because We Don't need to Change 5 dollars bill;
            }
            // For 10$
            else if(currentBill == 10) {
                if(fives == 0) {
                    return false; // When No change is availabe Simply return
                }
                fives--;
                tens++;
            } else if (currentBill == 20) {
                if(tens > 0 && fives > 0) {
                    tens--;
                    fives--;
                }
                // If we Go more than 3 Fives
                else if(fives >= 3) {
                    fives -= 3;
                }
            
                else {
                    return false;
                }
            }
        }
        return true;
    }
};