// Problem: Remove Nth Node From End of List
// Pattern: Linked List + Fast & Slow Pointers
// TC: O(n)
// SC: O(1)
//
// Idea:
// Maintain a gap of n+1 nodes between fast and slow.
// When fast reaches the end, slow will be right before
// the node that needs to be removed.

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Create a dummy node to handle the edge case of deleting the head itself
        ListNode* dummy = new ListNode(0, head);
        ListNode* slow = dummy;
        ListNode* fast = dummy;
        
        // 1. Move fast pointer n + 1 steps ahead
        for (int i = 0; i <= n; i++) {
            fast = fast->next;
        }
        
        // 2. Slide both pointers together
        while (fast != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }
        
        // 3. Delete the target node
        ListNode* toDelete = slow->next;
        slow->next = slow->next->next;
        delete toDelete;
        
        // 4. Safely return the true head and clean up the dummy
        ListNode* newHead = dummy->next;
        delete dummy;
        
        return newHead;
    }
};