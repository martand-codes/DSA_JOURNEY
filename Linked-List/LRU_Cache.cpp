/*
------------------------------------------------------------
Problem : LRU Cache (LeetCode 146)
Pattern : Hash Map + Doubly Linked List

Time Complexity :
- get() : O(1)
- put() : O(1)

Space Complexity : O(Capacity)

Idea:
- Use an unordered_map to provide O(1) lookup of a key.
- Use a doubly linked list to maintain the order of
  recently used nodes.
- The node closest to head is the Most Recently Used
  (MRU) node.
- The node closest to tail is the Least Recently Used
  (LRU) node.
- Whenever a key is accessed or inserted, move its node
  to the front.
- When capacity is exceeded, remove the node immediately
  before the tail and erase its key from the hash map.

Dummy head and tail nodes are used to simplify insertion
and deletion by eliminating special cases for the
beginning and end of the list.

Key Insight:
The hash map provides O(1) access while the doubly linked
list provides O(1) insertion and deletion. Combining both
allows get() and put() to operate in O(1) time.

------------------------------------------------------------
*/


class LRUCache {
private:
    struct Node {
        int key;
        int val;
        Node* prev;
        Node* next;
        Node(int k, int v) : key(k), val(v), prev(nullptr), next(nullptr) {}
    };

    int capacity;
    unordered_map<int, Node*> cache; 
    Node* head;
    Node* tail;
    void removeNode(Node* node) {
        Node* prevNode = node->prev;
        Node* nextNode = node->next;
        
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }
    void insertAfterHead(Node* node) {
        Node* nextNode = head->next;
        
        head->next = node;
        node->prev = head;
        
        node->next = nextNode;
        nextNode->prev = node;
    }

public:
    LRUCache(int cap) {
        capacity = cap;
        
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if (cache.find(key) == cache.end()) {
            return -1;
        }
        Node* node = cache[key];
        removeNode(node);
        insertAfterHead(node);
        return node->val;
    }
    
    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            Node* node = cache[key];
            node->val = value;
            removeNode(node);
            insertAfterHead(node);
            
        } else {
            Node* newNode = new Node(key, value);
            cache[key] = newNode;
            insertAfterHead(newNode);
            if (cache.size() > capacity) {
                Node* lru = tail->prev;
                cache.erase(lru->key);
                removeNode(lru);
                delete lru;
            }
        }
    }
};