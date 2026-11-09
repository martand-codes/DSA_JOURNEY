/*
------------------------------------------------------------
Problem : Word Search II (LeetCode 212)
Pattern : Trie / DFS / Backtracking / Matrix Traversal /
          Prefix Pruning

Time Complexity :
Trie Construction : O(W * L)
Board Search     : O(M * N * 4^L) Worst Case
Overall          : O(W * L + M * N * 4^L)

Space Complexity : O(W * L + L)

Idea:
Find all dictionary words present in a character board
using a Trie combined with DFS and backtracking.

Trie Construction:
- Insert every dictionary word into the Trie.
- Each TrieNode contains 26 child pointers.
- Store the complete word at its terminal node.
- This allows words to be identified immediately
  when their corresponding Trie nodes are reached.

For DFS:
- Start searching from every cell in the board.
- Check whether the current character exists as a
  child of the current TrieNode.
- Stop immediately if the character is unavailable
  in the Trie or the cell is already visited.
- Move into the corresponding TrieNode.
- If the node contains a complete word:
  - Add the word to the result.
  - Clear the stored word to prevent duplicates.
- Mark the current board cell as visited using '#'.
- Explore all four adjacent directions:
  Up, Down, Left, and Right.
- Restore the original character after exploration
  to backtrack and allow other paths to use it.

Key Insight:
Combining Trie prefix pruning with DFS avoids exploring
board paths that cannot form any dictionary word.

The Trie eliminates unnecessary searches by stopping
whenever the current character sequence does not
match any dictionary prefix.

Clearing the terminal word after discovery ensures
that the same dictionary word is not added repeatedly.

M represents the number of board rows.
N represents the number of board columns.
W represents the number of dictionary words.
L represents the maximum dictionary word length.

Trie construction takes O(W * L) time.

In the worst case, DFS explores up to four directions
for every character along a path of length L,
resulting in O(M * N * 4^L) board-search time.

The Trie requires O(W * L) space in the worst case,
while DFS recursion requires O(L) auxiliary space.

------------------------------------------------------------
*/

class Solution {
private:
    struct TrieNode {
        TrieNode* children[26];
        std::string word;
        
        TrieNode() {
            word = "";
            for (int i = 0; i < 26; i++) {
                children[i] = nullptr;
            }
        }
        
        ~TrieNode() {
            for (int i = 0; i < 26; i++) {
                delete children[i];
            }
        }
    };

    void insert(TrieNode* root, const std::string& word) {
        TrieNode* curr = root;
        for (char c : word) {
            int idx = c - 'a';
            if (!curr->children[idx]) {
                curr->children[idx] = new TrieNode();
            }
            curr = curr->children[idx];
        }
        curr->word = word;
    }

    void dfs(std::vector<std::vector<char>>& board, int r, int c, TrieNode* curr, std::vector<std::string>& result) {
        char ch = board[r][c];
        int idx = ch - 'a';
        
        if (ch == '#' || !curr->children[idx]) {
            return;
        }
        
        curr = curr->children[idx];
        
        if (!curr->word.empty()) {
            result.push_back(curr->word);
            curr->word = ""; 
        }
        
        board[r][c] = '#';
        
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (nr >= 0 && nr < board.size() && nc >= 0 && nc < board[0].size() && board[nr][nc] != '#') {
                dfs(board, nr, nc, curr, result);
            }
        }
        
        board[r][c] = ch; 
    }

    TrieNode* root;

public:
    std::vector<std::string> findWords(std::vector<std::vector<char>>& board, std::vector<std::string>& words) {
        root = new TrieNode();
        for (const std::string& w : words) {
            insert(root, w);
        }

        std::vector<std::string> result;
        int m = board.size();
        int n = board[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dfs(board, i, j, root, result);
            }
        }
        delete root; 
        return result;
    }
};