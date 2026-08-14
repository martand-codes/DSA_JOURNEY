/*
------------------------------------------------------------
Problem : Merge Two Sorted Lists (LeetCode 21)
Pattern : Linked List

Time Complexity : O(N + M)
Space Complexity : O(1)

Idea:
- Use a dummy/sentinel node to simplify construction
  of the merged linked list.
- Maintain a tail pointer representing the last node
  in the merged list.
- Compare the current nodes of both lists.
- Attach the smaller node to tail and advance that list.
- Continue until one list is exhausted.
- Attach the remaining portion of the other list directly.

Key Insight:
Because both lists are already sorted, at every step
the smaller current node must be the next node in the
merged list. The existing nodes can be reused directly,
so no additional nodes are required.

------------------------------------------------------------
*/

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode newList(0);
        ListNode* tail = &newList;

        while(list1 != nullptr && list2 != nullptr) {
            if(list1->val <= list2->val) {
                tail->next = list1;
                list1 = list1->next;
            } else {
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next;
        }
        if(list1 != nullptr) {
            tail->next = list1;
        } else {
            tail->next = list2;
        }
        return newList.next;
    }
};
