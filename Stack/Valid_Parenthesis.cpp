class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        
        for (char c : s) {
            // If it's an opening bracket, push it
            if (c == '(' || c == '{' || c == '[') {
                st.push(c);
            } 
            // If it's a closing bracket
            else {
                // If a closing bracket appears but the stack is empty, it's invalid!
                if (st.empty()) return false;
                
                char top = st.top();
                if ((c == ')' && top == '(') || 
                    (c == '}' && top == '{') || 
                    (c == ']' && top == '[')) {
                    st.pop(); // Valid match found, pop it
                } else {
                    return false; // Mismatch found
                }
            }
        }
        
        // If the stack is empty, all brackets were perfectly matched
        return st.empty();
    }
};