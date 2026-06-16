// Problem: Reorder List
// Pattern: Fast & Slow Pointers + Linked List Reversal + Merging
// TC: O(n)
// SC: O(1)
//
// Idea:
// 1. Find the middle of the linked list.
// 2. Reverse the second half.
// 3. Merge the two halves alternately.
//
// Example:
// 1 -> 2 -> 3 -> 4 -> 5
//
// Becomes:
//
// 1 -> 5 -> 2 -> 4 -> 3

class Solution {
public:
    void reorderList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return;
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode* curr = slow->next;
        slow->next = nullptr; 
        ListNode* prev = nullptr;
        
        while (curr != nullptr) {
            ListNode* nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        ListNode* first = head;
        ListNode* second = prev; 
        while (second != nullptr) {
            ListNode* tmp1 = first->next;
            ListNode* tmp2 = second->next;
            first->next = second;
            second->next = tmp1;
            first = tmp1;
            second = tmp2;
        }
    }
};