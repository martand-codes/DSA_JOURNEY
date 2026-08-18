/*
------------------------------------------------------------
Problem : Remove Nth Node From End of List (LeetCode 19)
Pattern : Linked List / Two Pointers / Dummy Node

Time Complexity : O(N)
Space Complexity : O(1)

Idea:
- Create a dummy node before the head to handle cases
  where the head itself needs to be removed.
- Maintain two pointers:
  - travellingNode : moves ahead to create a fixed gap.
  - pointingDelete : follows behind and eventually points
    to the node immediately before the node to be deleted.
- Move travellingNode n + 1 positions ahead.
- Move both pointers together until travellingNode
  reaches nullptr.
- At this point, pointingDelete is positioned immediately
  before the target node.
- Skip the target node by changing the next pointer.

Key Insight:
Creating a gap of n + 1 between the two pointers ensures
that when the front pointer reaches the end, the second
pointer is exactly one node before the nth node from the end.

The dummy node also allows the same logic to work when
the node being removed is the head.

------------------------------------------------------------
*/

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummyNode = new ListNode(0, head);
        ListNode* travellingNode = dummyNode;
        ListNode* pointingDelete = dummyNode;

        for(int i = 0; i <= n; i++) {
            travellingNode = travellingNode->next;
        }

        while(travellingNode != nullptr) {
            travellingNode = travellingNode->next;
            pointingDelete = pointingDelete->next;
        }
        pointingDelete->next = pointingDelete->next->next;

        return dummyNode->next;
    }
};
