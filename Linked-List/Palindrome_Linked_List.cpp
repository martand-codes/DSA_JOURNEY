// Problem: Palindrome Linked List
// Pattern: Linked List + Fast & Slow Pointers + In-Place Reversal
// TC: O(n)
// SC: O(1)
//
// Idea:
// 1. Find the middle using fast and slow pointers.
// 2. Reverse the second half of the list.
// 3. Compare both halves node by node.

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;
        
        // 1. Find the middle of the linked list
        ListNode* slow = head;
        ListNode* fast = head;

        // The 2 pointers strategy

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // 2. Reverse the second half of the list (Starting from 'slow')
        ListNode* prev = nullptr;
        ListNode* current = slow;
        while (current != nullptr) {
            ListNode* nxt = current->next;
            current->next = prev;
            prev = current;
            current = nxt;
        }
        
        // 3. Compare the first half and the reversed second half
        ListNode* firstHalf = head;
        ListNode* secondHalf = prev; // 'prev' is now the head of the reversed second half
        
        while (secondHalf != nullptr) {
            if (firstHalf->val != secondHalf->val) {
                return false; // Mismatch found, not a palindrome!
            }
            firstHalf = firstHalf->next;
            secondHalf = secondHalf->next;
        }
        
        return true;
    }
};