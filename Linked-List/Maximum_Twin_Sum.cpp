// Problem: Maximum Twin Sum of a Linked List
// Pattern: Linked List + Fast & Slow Pointers + In-Place Reversal
// TC: O(n)
// SC: O(1)
//
// Idea:
// 1. Find the middle of the linked list.
// 2. Reverse the second half.
// 3. Traverse both halves simultaneously.
// 4. Compute twin sums and track the maximum.


class Solution {
    public:
        int pairSum(ListNode* head) {

            // Using 2 pointers to find the middle

            ListNode* slow = head;
            ListNode* fast = head;
            while(fast != NULL && fast->next != NULL) {
                slow = slow->next;
                fast = fast->next->next;
            }

            // Reversing through the middle to find the sum
            ListNode* current = slow;
            ListNode* previous = NULL;
            while(current != NULL) {
                ListNode* NEXT = current->next;
                current->next = previous;
                previous = current;
                current = NEXT;
            }

            // As the second Half is sorted just need to find the sum

            int maxSum = 0;
            ListNode* firstHalf = head;
            ListNode* secondHalf = previous;

            while(secondHalf != NULL) {
                int currentSum = firstHalf->val + secondHalf->val;
                maxSum = max(maxSum, currentSum);
                firstHalf = firstHalf->next;
                secondHalf = secondHalf->next;
            }

            return maxSum;

        }
};