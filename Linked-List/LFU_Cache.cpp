/*
------------------------------------------------------------
Problem : LFU Cache (LeetCode 460)
Pattern : Hash Map + Frequency Buckets + Doubly Linked List

Time Complexity :
- get() : O(1) average
- put() : O(1) average

Space Complexity : O(Capacity)

Idea:
- LFU stands for Least Frequently Used.
- Every node stores:
    - key
    - value
    - frequency
- Use `freqMap` to group nodes according to their
  current frequency.
- Each frequency has a doubly linked list where:
    - Front  = Most Recently Used
    - Back   = Least Recently Used
- Use `keyMap` to directly locate the exact node belonging
  to a key.
- `minFreq` stores the lowest frequency currently present,
  allowing eviction in O(1).

Operations:
1. get(key):
   - Find the node using keyMap.
   - Increase its frequency.
   - Move it to the front of the next frequency list.
   - Return its value.

2. put(key, value):
   - If the key already exists:
       Update its value and increase its frequency.
   - If the cache is full:
       Find the LRU node from the lowest-frequency list.
       Remove it from both maps.
   - Insert the new node into frequency 1.
   - Reset minFreq to 1.

Eviction Rule:
- First remove the Least Frequently Used node.
- If multiple nodes have the same frequency, remove the
  Least Recently Used node among them.

Key Insight:
A single data structure cannot efficiently provide both
frequency-based eviction and O(1) key lookup.

Therefore we combine:
    Hash Map
        ↓
    Direct key → node access

    Frequency Map
        ↓
    Frequency → doubly linked list

    minFreq
        ↓
    Direct access to the eviction bucket

This allows both get() and put() to run in O(1) average time.

------------------------------------------------------------
*/

class LFUCache {
private:
    // Our custom data packet stored inside the linked lists
    struct Node {
        int key;
        int val;
        int freq;
        Node(int k, int v) : key(k), val(v), freq(1) {}
    };

    int capacity;
    int minFreq; // Tracks the lowest frequency for O(1) eviction
    
    // Map 1: frequency -> Doubly Linked List of Nodes
    unordered_map<int, list<Node>> freqMap;
    
    // Map 2: key -> Pointer (iterator) to the exact Node in the list
    unordered_map<int, list<Node>::iterator> keyMap;

    // Helper: Upgrades a node to the next frequency floor
    void updateFrequency(int key) {
        // 1. Grab the node from its current list
        auto nodePtr = keyMap[key];
        int val = nodePtr->val;
        int freq = nodePtr->freq;
        
        // 2. Erase it from its current frequency floor
        freqMap[freq].erase(nodePtr);
        
        // 3. Did we just empty out the lowest floor? 
        // If so, the minimum frequency goes up!
        if (freqMap[freq].empty() && minFreq == freq) {
            minFreq++;
        }
        
        // 4. Upgrade the node's frequency and put it at the FRONT of the next floor up
        freqMap[freq + 1].push_front(Node(key, val));
        freqMap[freq + 1].front().freq = freq + 1;
        
        // 5. Update our keyMap to point to this shiny new location
        keyMap[key] = freqMap[freq + 1].begin();
    }

public:
    LFUCache(int capacity) {
        this->capacity = capacity;
        this->minFreq = 0;
    }
    
    int get(int key) {
        if (keyMap.find(key) == keyMap.end()) {
            return -1;
        }
        
        // Node exists! Upgrade its frequency and return the value
        updateFrequency(key);
        return keyMap[key]->val;
    }
    
    void put(int key, int value) {
        if (capacity == 0) return;
        
        if (keyMap.find(key) != keyMap.end()) {
            // Key already exists: update value and upgrade frequency
            keyMap[key]->val = value;
            updateFrequency(key);
        } else {
            // New Key! Do we need to evict someone?
            if (keyMap.size() == capacity) {
                // Find the LRU node on the lowest frequency floor
                // (The one trapped at the very back of the list)
                int lruKey = freqMap[minFreq].back().key;
                
                // Erase it from both maps
                freqMap[minFreq].pop_back();
                keyMap.erase(lruKey);
            }
            
            // Insert the brand new node at the front of Floor 1
            freqMap[1].push_front(Node(key, value));
            keyMap[key] = freqMap[1].begin();
            minFreq = 1; // A new element always resets minFreq to 1
        }
    }
};