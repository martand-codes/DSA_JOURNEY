/*
------------------------------------------------------------
Problem : Merge k Sorted Lists (LeetCode 23)
Pattern : Linked List + Priority Queue / Min Heap

Time Complexity : O(N log K)
Space Complexity : O(K)

Where:
- N = Total number of nodes across all linked lists.
- K = Number of linked lists.

Idea:
- Since every linked list is already sorted, maintain a
  min heap containing the current smallest node from each
  non-empty list.
- Initially, insert the head node of every list into the
  min heap.
- Repeatedly:
  1. Extract the smallest node.
  2. Attach it to the result list.
  3. If that node has a next node, insert the next node
     into the heap.
- Continue until the heap becomes empty.

Key Insight:
At any moment, the heap contains at most one candidate
from each list. Since each list is sorted, after removing
a node, only its next node can become the next candidate
from that list.

A custom comparator converts C++'s default max heap into
a min heap based on ListNode->val.

Dummy Node:
A dummy node simplifies construction of the merged list
by providing a fixed starting point for the result.

------------------------------------------------------------
*/

class Solution {
    struct Compare {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, Compare> minHeap;
        
        for (ListNode* node : lists) {
            if (node != nullptr) {
                minHeap.push(node);
            }
        }
        
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;
        while (!minHeap.empty()) {
            ListNode* smallest = minHeap.top();
            minHeap.pop();
            curr->next = smallest;
            curr = curr->next;
            
            if (smallest->next != nullptr) {
                minHeap.push(smallest->next);
            }
        }
        
        ListNode* head = dummy->next;
        delete dummy; 
        return head;
    }
};