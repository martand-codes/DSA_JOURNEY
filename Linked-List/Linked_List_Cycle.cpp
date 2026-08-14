/*
------------------------------------------------------------
Problem : Linked List Cycle (LeetCode 141)
Pattern : Fast & Slow Pointers / Floyd's Cycle Detection

Time Complexity : O(N)
Space Complexity : O(1)

Idea:
- Maintain two pointers:
  - slow moves one node at a time.
  - fast moves two nodes at a time.
- If there is no cycle, fast will eventually reach
  nullptr.
- If a cycle exists, fast will eventually catch slow
  inside the cycle.

Key Insight:
A faster pointer moving through a cycle must eventually
meet the slower pointer. This allows cycle detection
without storing visited nodes.

Alternative Approach:
- Store every visited node in an unordered_set.
- This also takes O(N) time but requires O(N) extra space,
  so it does not satisfy the O(1) space requirement.

------------------------------------------------------------
*/

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* current = head;
        if(head == nullptr || head->next == nullptr) {
            return false;
        }
        ListNode* fast = current;
        ListNode* slow = current;
        while(fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow) {
                return true;
            } 
        }
        return false;
    }
};