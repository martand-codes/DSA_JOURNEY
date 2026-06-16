// Problem: Process String
// Pattern: String Simulation
//
// Operations:
// letter -> append
// '*'    -> remove last character
// '#'    -> duplicate current string
// '%'    -> reverse current string
//
// TC: O(final_string_length)
// SC: O(final_string_length)

class Solution {
public:

    string processStr(string s) {
        string res = "";
        
        for (char c : s) {
            if (c >= 'a' && c <= 'z') {
                res += c;
            } else if (c == '*') {
                if (!res.empty()) {
                    res.pop_back();
                }
            } else if (c == '#') {
                res += res; 
            } else if (c == '%') {
                reverse(res.begin(), res.end());
            }
        }
        
        return res;
    }
};