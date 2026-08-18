/*
------------------------------------------------------------
Problem : Reorder List (LeetCode 143)
Pattern : Linked List / Fast & Slow Pointers

Time Complexity : O(N)
Space Complexity : O(1)

Idea:
- Use slow and fast pointers to find the middle of
  the linked list.
- Split the list into two halves.
- Reverse the second half in-place.
- Merge the two halves alternately.

Example:
1 → 2 → 3 → 4 → 5

First half:
1 → 2 → 3

Second half:
4 → 5

Reverse:
5 → 4

Merge:
1 → 5 → 2 → 4 → 3

Key Insight:
The problem combines three fundamental linked-list
techniques:
1. Fast/slow pointers to find the middle.
2. In-place pointer reversal.
3. Alternating merge of two linked lists.

No additional data structure is required, allowing
the solution to achieve O(1) extra space.
------------------------------------------------------------
*/

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
