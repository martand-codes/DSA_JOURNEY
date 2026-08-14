
/*
------------------------------------------------------------
Problem : Reverse Linked List (LeetCode 206)
Pattern : Linked List

Time Complexity : O(N)
Space Complexity : O(1)

Idea:
- Maintain three pointers:
  - previous : points to the already reversed portion.
  - current  : points to the current node being processed.
  - next     : temporarily stores the next node.
- Save current->next before reversing the pointer.
- Point current->next to previous.
- Move previous and current one step forward.
- Continue until the entire list is reversed.

Key Insight:
Always save the next node before changing current->next,
otherwise the remaining portion of the linked list will
be lost.

------------------------------------------------------------
*/

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        // Base Case
        if(head == nullptr) {
            return nullptr;
        }
        ListNode* current = head;
        ListNode* previous = nullptr;
        while(current != nullptr) {
            ListNode* next = current->next;
            current->next = previous;
            previous = current;
            current = next;
        }
        return previous;
    }
};


// Using Recursion

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        // Base Case: Empty list or we reached the very last node
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        
        // Recurse all the way to the end to find the new head
        ListNode* newHead = reverseList(head->next);
        
        // Reverse the link between the current node and the next node
        head->next->next = head;
        head->next = nullptr; // Cut the original forward link
        
        return newHead;
    }
};