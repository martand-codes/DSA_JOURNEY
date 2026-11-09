/*
------------------------------------------------------------
Problem : Implement Trie (Prefix Tree) (LeetCode 208)
Pattern : Trie / Prefix Tree / Tree-Based String
          Searching / Character Mapping

Time Complexity :
Insert     : O(L)
Search     : O(L)
StartsWith : O(L)

Space Complexity : O(T * 26) Worst Case

Idea:
Implement a Trie using dynamically allocated nodes,
where each node contains an array of 26 child pointers
representing lowercase English alphabet characters.

Each node maintains:
- children[26] : Pointers to subsequent character nodes.
- isEnd        : Indicates whether a complete word
                 terminates at the current node.

For insert():
- Start traversal from the root.
- Convert each character into an index using c - 'a'.
- Create a new TrieNode if the corresponding child
  pointer does not exist.
- Move to the child node.
- Mark the final node as the end of the word.

For search():
- Traverse the Trie character by character.
- Return false if any required child node is missing.
- After traversing the complete word, return true
  only if the final node is marked as isEnd.

For startsWith():
- Traverse the Trie character by character.
- Return false if any required child node is missing.
- Return true if the entire prefix exists in the Trie,
  regardless of whether it represents a complete word.

Key Insight:
A Trie stores strings by sharing common prefixes.

Each character corresponds to an edge between nodes,
allowing prefix-based searches without repeatedly
comparing complete strings.

The isEnd flag distinguishes complete words from
prefixes that exist only as part of longer words.

L represents the length of the word or prefix.
T represents the total number of Trie nodes.

Each node requires 26 child pointers, resulting in
O(26 * T) space, which simplifies to O(T).

The destructor recursively releases allocated nodes
to prevent memory leaks.

------------------------------------------------------------
*/

class Trie {
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
        
        // Optional destructor to prevent memory leaks in production environments
        ~TrieNode() {
            for (int i = 0; i < 26; i++) {
                delete children[i];
            }
        }
    };
    
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }
    
    ~Trie() {
        delete root;
    }
    
    void insert(std::string word) {
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
        TrieNode* curr = root;
        for (char c : word) {
            int idx = c - 'a';
            if (!curr->children[idx]) {
                return false;
            }
            curr = curr->children[idx];
        }
        return curr->isEnd;
    }
    
    bool startsWith(std::string prefix) {
        TrieNode* curr = root;
        for (char c : prefix) {
            int idx = c - 'a';
            if (!curr->children[idx]) {
                return false;
            }
            curr = curr->children[idx];
        }
        return true;
    }
};