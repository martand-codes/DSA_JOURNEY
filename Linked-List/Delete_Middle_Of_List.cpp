// Problem: Delete the Middle Node of a Linked List
// Pattern: Fast & Slow Pointers
// TC: O(n)
// SC: O(1)
//
// Idea:
// Use fast and slow pointers to locate the middle node.
// Track the node before slow and bypass the middle node.

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return nullptr;
        }
        
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;
        while (fast != nullptr && fast->next != nullptr) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = slow->next;
        delete slow;
        
        return head;
    }
};