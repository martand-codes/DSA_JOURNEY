/*
------------------------------------------------------------
Problem : Simplify Path (LeetCode 71)
Pattern : Stack / String Parsing

Time Complexity  : O(N)
Space Complexity : O(N)

Idea:
- Process the Unix path one directory/component at a time.
- Use a stack to represent the directories currently
  present in the canonical path.

Rules:

    "directory"
        → Push directory onto the stack.

    "."
        → Current directory.
        → Ignore it.

    ".."
        → Move to the parent directory.
        → Pop the top directory if the stack is not empty.

    ""
        → Caused by consecutive '/' characters or leading/
          trailing '/'.
        → Ignore it.

Example:

    Input:
        /a/./b/../../c/

    Process:

        a   → [a]
        .   → [a]
        b   → [a, b]
        ..  → [a]
        ..  → []
        c   → [c]

    Result:
        /c


Important:
If ".." is encountered while the stack is empty, we do
nothing.

Example:

    /../../

    Stack remains empty.

    Result:
        /


Why stack?

The most recent directory is the one affected by "..".

Example:

    /home/user/docs
              ↑
              top

    ".."

    removes "docs".

Therefore, LIFO behavior maps naturally to Unix
parent-directory navigation.


Final reconstruction:
- The stack contains directories in reverse order because
  we remove them from the top.
- Store them temporarily in a vector.
- Reverse the vector.
- Add '/' before every directory.

Example:

    Stack:
        [home, user, docs]

    Pop order:
        docs, user, home

    Reverse:
        home, user, docs

    Build:
        /home/user/docs


Key Insight:

Unix path normalization can be reduced to four stack rules:

    normal directory → PUSH
    "."              → IGNORE
    ".."             → POP
    "/" / empty      → IGNORE

------------------------------------------------------------
*/


class Solution {
public:
    string simplifyPath(string path) {
        stringstream ss(path);
        string segment;
        stack<string> st;
        while (getline(ss, segment, '/')) {
            if (segment == "" || segment == ".") {
                continue;
            }
            else if (segment == "..") {
                if (!st.empty()) {
                    st.pop();
                }
            } 

            else {
                st.push(segment);
            }
        }
        vector<string> temp;
        while (!st.empty()) {
            temp.push_back(st.top());
            st.pop();
        }
        reverse(temp.begin(), temp.end());
        string result = "";
        for (const string& dir : temp) {
            result += "/" + dir;
        }
        return result.empty() ? "/" : result;
    }
};