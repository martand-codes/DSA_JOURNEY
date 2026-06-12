class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // 1. Setup the Dummy Node and Tail pointer
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;
        
        // 2. The Zipper Loop
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val <= list2->val) {
                tail->next = list1;
                list1 = list1->next;
            } else {
                tail->next = list2;
                list2 = list2->next;
            }
            
            // Move the tail forward
            tail = tail->next;
        }
        
        // 3. Attach the leftovers
        if (list1 != nullptr) {
            tail->next = list1;
        } else {
            tail->next = list2;
        }
        
        // 4. Safely extract the real head and clean up the dummy node
        ListNode* head = dummy->next;
        delete dummy; 
        
        return head;
    }
};