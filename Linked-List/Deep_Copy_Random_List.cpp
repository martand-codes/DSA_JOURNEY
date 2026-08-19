/*
------------------------------------------------------------
Problem : Copy List with Random Pointer (LeetCode 138)
Pattern : Linked List / Hashing

Time Complexity : O(N)
Space Complexity : O(N)

Idea:
- Create a deep copy of every node and store the
  relationship between each original node and its clone
  in an unordered_map.
- First pass:
  Create all cloned nodes.
- Second pass:
  Connect the `next` and `random` pointers of every
  cloned node using the mapping.

Key Insight:
The random pointer can point to any node in the list,
including itself or nullptr. The hash map allows every
original node to be directly translated to its
corresponding cloned node.

Example:
Original Node  →  Cloned Node
     A         →       A'
     B         →       B'
     C         →       C'

If A.random → C,
then A'.random → C'.

------------------------------------------------------------
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) {
            return nullptr;
        }
        unordered_map<Node*, Node*> oldToNew;
        Node* curr = head;
        while (curr != nullptr) {
            oldToNew[curr] = new Node(curr->val);
            curr = curr->next;
        }
        curr = head;
        while (curr != nullptr) {
            oldToNew[curr]->next = oldToNew[curr->next];
            oldToNew[curr]->random = oldToNew[curr->random];
            curr = curr->next;
        }
        return oldToNew[head];
    }
};