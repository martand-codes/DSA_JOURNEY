/*
------------------------------------------------------------
Problem : Add Two Numbers (LeetCode 2)
Pattern : Linked List / Elementary Addition / Carry

Time Complexity : O(max(M, N))
Space Complexity : O(max(M, N))
(For the output linked list)

Idea:
- The digits are stored in reverse order, so we can add
  the numbers from left to right just like elementary
  addition.
- Maintain a carry value between additions.
- At every position:
  1. Get the current digit from l1 and l2.
  2. Add both digits and the carry.
  3. Store totalSum % 10 as the current digit.
  4. Store totalSum / 10 as the next carry.
- Continue while either list has nodes or a carry remains.
- Use a dummy node to simplify construction of the result.

Key Insight:
The linked lists already store the least significant digit
first, so no reversal is required. The carry naturally
propagates as we traverse both lists.

Example:
l1 = 2 → 4 → 3
l2 = 5 → 6 → 4

Represents:
342 + 465 = 807

Result:
7 → 0 → 8

------------------------------------------------------------
*/

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* current = dummy;
        int carry = 0;

        while(l1 != nullptr || l2 != nullptr || carry != 0) {
            int l1_left_val = (l1 != nullptr) ? l1->val : 0;
            int l2_left_val = (l2 != nullptr) ? l2->val : 0;

            int totalSum = l1_left_val + l2_left_val + carry;
            carry = totalSum / 10;
            int digit = totalSum % 10;

            current->next = new ListNode(digit);

            current = current->next;

            if(l1 != nullptr) {
                l1 = l1->next;
            }
            if(l2 != nullptr) {
                l2 = l2->next;
            }
        }
        return dummy->next;
    }
};