

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        // if empty or only 1 node, nothing to reverse
        if (head == nullptr) {
            return nullptr;
        }

        ListNode* current = head;
        ListNode* previous = nullptr;

        while (current != nullptr) {
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