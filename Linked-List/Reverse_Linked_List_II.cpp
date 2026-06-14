// Problem: Reverse Linked List II
// Pattern: Linked List + In-Place Reversal
// TC: O(n)
// SC: O(1)

// Idea:
// 1. Reach the left position.
// 2. Reverse nodes from left to right.
// 3. Reconnect the reversed section with the first and last parts.

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        // If the list is empty or there's nothing to reverse
        if (head == nullptr || left == right) return head;

        ListNode* temp = head;
        ListNode* prev = nullptr; 

        // For Left
        for (int i = 1; i < left; i++) {
            prev = temp;
            temp = temp->next;
        }

        ListNode* start = temp; 

        ListNode* revPrev = nullptr;
        ListNode* nxt = nullptr;
        
        for (int i = 0; i <= right - left; i++) {
            nxt = temp->next;
            temp->next = revPrev;
            revPrev = temp;
            temp = nxt;
        }

        // Stitching 
        if (prev != nullptr) {
            prev->next = revPrev; 
        } else {
            // Edge case: If left == 1 then there was no first half!
            head = revPrev; 
        }

        // Tie the end of our reversed section to the remaining tail of the list
        start->next = temp;

        return head;
    }
};


// Two Pass Solution



class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (head == nullptr || left == right) return head;

        // 1. Pass One: Traverse and collect values in the target range
        vector<int> extractedValues;
        ListNode* temp = head;
        int position = 1;

        while (temp != nullptr && position <= right) {
            if (position >= left) {
                extractedValues.push_back(temp->val);
            }
            temp = temp->next;
            position++;
        }

        // 2. The Flip: Reverse the values inside our standard vector
        reverse(extractedValues.begin(), extractedValues.end());

        // 3. Pass Two: Reset pointer and overwrite values in the target range
        temp = head;
        position = 1;
        int vectorIndex = 0;

        while (temp != nullptr && position <= right) {
            if (position >= left) {
                temp->val = extractedValues[vectorIndex];
                vectorIndex++;
            }
            temp = temp->next;
            position++;
        }

        return head;
    }
};