/*
------------------------------------------------------------
Problem : Reverse Linked List II (LeetCode 92)
Pattern : Linked List / Pointer Reversal

Time Complexity : O(N)
Space Complexity : O(1)

Idea:
- Traverse to the node at the `left` position while keeping
  track of the node immediately before it.
- Reverse only the portion of the list from `left` to `right`
  using the standard linked-list reversal technique.
- Reconnect the reversed section with the first and remaining
  portions of the list.
- Handle the special case where `left == 1`, meaning the head
  itself belongs to the reversed section.

Key Insight:
The standard linked-list reversal algorithm can be applied
to only a selected portion of the list. The original first
node of the reversed section becomes its tail after reversal,
allowing it to be connected to the remaining list.

Example:
1 → 2 → 3 → 4 → 5
left = 2, right = 4

After reversal:
1 → 4 → 3 → 2 → 5

------------------------------------------------------------
*/

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