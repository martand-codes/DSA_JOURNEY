/*
------------------------------------------------------------
Problem : Design Add and Search Words Data Structure
          (LeetCode 211)

Pattern : Trie / Prefix Tree / DFS / Backtracking /
          Wildcard Matching

Time Complexity :
AddWord : O(L)
Search  : O(26^L) Worst Case

Space Complexity : O(26 * T)

Idea:
Implement a Trie-based dictionary supporting insertion
of words and searching with the wildcard character '.'.

Each TrieNode contains:
- children[26] : Pointers to lowercase alphabet nodes.
- isEnd        : Indicates whether a complete word
                  terminates at the current node.

For addWord():
- Start traversal from the root.
- Convert each character into an index using c - 'a'.
- Create missing TrieNodes when necessary.
- Move to the corresponding child node.
- Mark the final node as the end of the word.

For search():
- Use a recursive helper function with the current
  TrieNode and character index.
- If the entire word has been traversed, return
  curr->isEnd.

For normal characters:
- Follow the corresponding child pointer.
- Return false if the required child does not exist.
- Recursively continue searching the remaining word.

For wildcard '.':
- Explore all existing child nodes.
- Recursively search the remaining characters
  through every possible alphabet branch.
- Return true if any branch successfully matches.
- Return false if every possible branch fails.

Key Insight:
The wildcard '.' can represent any lowercase letter.

Unlike ordinary Trie searching, wildcard searching
may require exploring multiple branches.

DFS and backtracking allow the search to explore
different character possibilities while preserving
the current word index and Trie traversal state.

L represents the length of the searched word.
T represents the total number of Trie nodes.

AddWord takes O(L) time.

Search takes O(26^L) time in the worst case when
wildcards cause extensive branching.

The Trie requires O(26 * T) space due to the
26 child pointers maintained by every node.

The destructor recursively releases allocated nodes
to prevent memory leaks.

------------------------------------------------------------
*/

class WordDictionary {
private:
    struct TrieNode {
        TrieNode* children[26];
        bool isEnd;
        
        TrieNode() {
            isEnd = false;
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
    
    TrieNode* root;
    bool searchHelper(const std::string& word, int index, TrieNode* curr) {
        if (index == word.length()) {
            return curr->isEnd;
        }
        
        char c = word[index];
        
        if (c == '.') {
            for (int i = 0; i < 26; i++) {
                if (curr->children[i] && searchHelper(word, index + 1, curr->children[i])) {
                    return true;
                }
            }
            return false;
        } else {
            int idx = c - 'a';
            if (!curr->children[idx]) {
                return false;
            }
            return searchHelper(word, index + 1, curr->children[idx]);
        }
    }

public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    ~WordDictionary() {
        delete root;
    }
    
    void addWord(std::string word) {
        TrieNode* curr = root;
        for (char c : word) {
            int idx = c - 'a';
            if (!curr->children[idx]) {
                curr->children[idx] = new TrieNode();
            }
            curr = curr->children[idx];
        }
        curr->isEnd = true;
    }
    
    bool search(std::string word) {
        return searchHelper(word, 0, root);
    }
};

