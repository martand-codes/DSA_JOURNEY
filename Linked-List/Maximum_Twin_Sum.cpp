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
        // 1. Find the middle of the linked list
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // 2. Reverse the second half of the list
        ListNode* prev = nullptr;
        ListNode* curr = slow;
        while (curr != nullptr) {
            ListNode* nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        
        // 3. Sum the twins and find the maximum
        int maxSum = 0;
        ListNode* firstHalf = head;
        ListNode* secondHalf = prev; // 'prev' is the new head of the reversed second half
        
        while (secondHalf != nullptr) {
            // Calculate twin sum
            int currentSum = firstHalf->val + secondHalf->val;
            maxSum = max(maxSum, currentSum);
            
            // Move both pointers forward
            firstHalf = firstHalf->next;
            secondHalf = secondHalf->next;
        }
        
        return maxSum;
    }
};