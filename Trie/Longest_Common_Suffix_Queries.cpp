// Problem: Longest Common Suffix Queries
// Pattern: Trie / String Processing
// TC: O(total characters in container + queries)
// SC: O(total characters)


class Solution {
    // Array-based node structure
    struct Node {
        int children[26];
        int best_index;
        
        Node(int idx) {
            for(int i = 0; i < 26; ++i) {
                children[i] = -1; // -1 indicates no child exists
            }
            best_index = idx;
        }
    };
    
public:
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        int n = wordsContainer.size();
        
        // 1. Find the global best index for an empty suffix match
        int global_best = 0;
        for (int i = 1; i < n; ++i) {
            if (wordsContainer[i].length() < wordsContainer[global_best].length()) {
                global_best = i;
            } 
        }
        
        // 2. Initialize the contiguous memory Trie
        vector<Node> trie;
        // Pre-allocate memory to prevent costly vector reallocations. 
        // Max sum of lengths is 5 * 10^5, so we won't exceed this many nodes.
        trie.reserve(500005); 
        
        // Add the root node at index 0
        trie.push_back(Node(global_best)); 
        
        // Tie-breaker logic
        auto updateBest = [&](int& current_best, int candidate) {
            if (wordsContainer[candidate].length() < wordsContainer[current_best].length()) {
                current_best = candidate;
            } else if (wordsContainer[candidate].length() == wordsContainer[current_best].length() && candidate < current_best) {
                current_best = candidate;
            }
        };
        
        // 3. Build the Trie with reversed words
        for (int i = 0; i < n; ++i) {
            int curr = 0; // Always start at the root (index 0)
            updateBest(trie[curr].best_index, i); 
            
            int len = wordsContainer[i].length();
            for (int j = len - 1; j >= 0; --j) {
                int char_idx = wordsContainer[i][j] - 'a';
                
                // If child doesn't exist, create it and link its index
                if (trie[curr].children[char_idx] == -1) {
                    trie[curr].children[char_idx] = trie.size();
                    trie.push_back(Node(i));
                } else {
                    updateBest(trie[trie[curr].children[char_idx]].best_index, i);
                }
                
                // Move to the child node
                curr = trie[curr].children[char_idx];
            }
        }
        
        // 4. Process the queries
        vector<int> ans;
        ans.reserve(wordsQuery.size());
        
        for (const string& q : wordsQuery) {
            int curr = 0;
            int len = q.length();
            
            for (int j = len - 1; j >= 0; --j) {
                int char_idx = q[j] - 'a';
                if (trie[curr].children[char_idx] == -1) {
                    break; // Stop when the common suffix ends
                }
                curr = trie[curr].children[char_idx];
            }
            ans.push_back(trie[curr].best_index);
        }
        
        return ans;
    }
};