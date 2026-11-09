/*
------------------------------------------------------------
Problem : Reverse Nodes in k-Group (LeetCode 25)
Pattern : Linked List / Iterative Reversal / Pointer
          Manipulation / Dummy Node

Time Complexity :
Length Calculation : O(N)
Group Reversal    : O(N)
Overall            : O(N)

Space Complexity : O(1)

Idea:
Reverse the linked list in consecutive groups of k
nodes while preserving the relative order of any
remaining nodes that do not form a complete group.

- First calculate the total number of nodes.
- Create a dummy node pointing to the original head.
- Maintain prevGroupTail to connect previously
  reversed groups with the next reversed group.
- Process the list only while at least k nodes remain.
- Reverse exactly k nodes using three pointers:
  prev, curr, and nxt.
- Connect the previous group's tail to the new
  head of the reversed group.
- Connect the original group's head to the next
  unreversed node.
- Update prevGroupTail to the original group's head.
- Leave the remaining nodes untouched if fewer
  than k nodes remain.
- Return the new head through the dummy node.

Key Insight:
Reversing a group changes its head and tail.

The original group head becomes the new group tail,
while the original group tail becomes the new head.

The dummy node simplifies handling the first group,
and prevGroupTail maintains connections between
successive reversed groups.

N represents the total number of nodes in the list,
and k represents the group size.

Every node is traversed a constant number of times,
resulting in O(N) time and O(1) auxiliary space.

------------------------------------------------------------
*/

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;
        int count = 0;
        ListNode* curr = head;
        while (curr != nullptr) {
            count++;
            curr = curr->next;
        }
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prevGroupTail = dummy;
        curr = head;
        while (count >= k) {
            ListNode* prev = nullptr;
            ListNode* groupHead = curr; 
            for (int i = 0; i < k; i++) {
                ListNode* nxt = curr->next;
                curr->next = prev;
                prev = curr;
                curr = nxt;
            }
            ListNode* nxtGroupHead = prevGroupTail->next;
            prevGroupTail->next = prev;
            nxtGroupHead->next = curr;
            prevGroupTail = nxtGroupHead;
            count -= k;
        }
        ListNode* newHead = dummy->next;
        delete dummy; 
        return newHead;
    }
};