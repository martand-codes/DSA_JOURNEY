// Problem: Reverse Nodes in k-Group
// Pattern: Linked List
// TC: O(N)
// SC: O(1)

// Problem: Reverse Nodes in k-Group
// Pattern: Linked List
// TC: O(N)
// SC: O(1)

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;
        
        // 1. Count the total number of nodes
        int count = 0;
        ListNode* curr = head;
        while (curr != nullptr) {
            count++;
            curr = curr->next;
        }
        
        // 2. Setup Dummy Node
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prevGroupTail = dummy;
        curr = head;
        
        // 3. Reverse in chunks of k
        while (count >= k) {
            ListNode* prev = nullptr;
            ListNode* groupHead = curr; // Will become the tail of the chunk
            
            // Your perfect standard reversal code, capped at k iterations
            for (int i = 0; i < k; i++) {
                ListNode* nxt = curr->next;
                curr->next = prev;
                prev = curr;
                curr = nxt;
            }
            
            // 4. Re-link the chunks
            ListNode* nxtGroupHead = prevGroupTail->next;
            prevGroupTail->next = prev;
            nxtGroupHead->next = curr;
            
            // Shift the anchor forward
            prevGroupTail = nxtGroupHead;
            count -= k;
        }
        
        // 5. Clean up the dummy node safely
        ListNode* newHead = dummy->next;
        delete dummy; 
        return newHead;
    }
};