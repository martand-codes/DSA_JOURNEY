/*
------------------------------------------------------------
Problem : Reverse String (LeetCode 344)
Pattern : Two Pointers

Time Complexity : O(N)
Space Complexity : O(1)

Idea:
- Initialize two pointers at the beginning and end
  of the string.
- Swap the characters at both pointers.
- Move the pointers toward each other until they
  meet or cross.

Key Insight:
Swapping symmetric characters from both ends
reverses the string in-place without using any
extra memory.
------------------------------------------------------------
*/

class Solution {
public:
    void reverseString(vector<char>& s) {
        int left = 0;
        int right = s.size() - 1;
        
        while (left < right) {
            swap(s[left], s[right]);
            left++;
            right--;
        }
    }
};


/* Solved using Stack

class Solution {
public:
    void reverseString(vector<char>& s) {

        stack<char> st;

        for(char c : s) {
            st.push(c);
        }

        for(int i = 0; i < s.size(); i++) {
            s[i] = st.top();
            st.pop();
        }
    }
};

*/