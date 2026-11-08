/*
------------------------------------------------------------
Problem : Design HashMap (LeetCode 706)
Pattern : Hashing / Separate Chaining / Collision Handling

Time Complexity :
Put    : O(K) Average
Get    : O(K) Average
Remove : O(K) Average

Space Complexity : O(B + N)

Idea:
Implement a HashMap using an array of buckets, where each
bucket contains a linked list of key-value pairs.

Use a hash function (key % numBuckets) to determine the
bucket index for every key.

For put():
- Traverse the bucket to check whether the key exists.
- Update its value if found.
- Otherwise, insert a new key-value pair.

For get():
- Traverse the corresponding bucket and return the value
  associated with the key.
- Return -1 if the key does not exist.

For remove():
- Traverse the bucket and erase the matching key-value
  pair if it exists.

Key Insight:
Hashing provides fast bucket access, while separate
chaining handles collisions by storing multiple
key-value pairs in the same bucket.

K represents the number of key-value pairs in the
selected bucket, B represents the number of buckets,
and N represents the total number of stored keys.

Average operations are O(1) when collisions are limited,
but can degrade to O(N) in the worst case.
------------------------------------------------------------
*/

/*

class MyHashMap {
private:
    vector<int> table;
public:
    MyHashMap() {
        table.resize(1000001, -1);
    }
    void put(int key, int value) {
        table[key] = value;
    }
    int get(int key) {
        return table[key];
    }
    void remove(int key) {
        table[key] = -1;
    }
};

*/
class MyHashMap {
private:
    int numBuckets;
    vector<list<pair<int, int>>> buckets;
    // The Hash Function
    int hash_func(int key) {
        return key % numBuckets;
    }

public:
    MyHashMap() {
        numBuckets = 10000; // To eliminate Collisions
        buckets.resize(numBuckets);
    }
    void put(int key, int value) {
        int index = hash_func(key);
        for (auto& kv : buckets[index]) {
            if (kv.first == key) {
                kv.second = value;
                return;
            }
        }
        buckets[index].push_back({key, value});
    }
    
    int get(int key) {
        int index = hash_func(key);
        for (auto& kv : buckets[index]) {
            if (kv.first == key) {
                return kv.second;
            }
        }
        return -1;
    }
    
    void remove(int key) {
        int index = hash_func(key);
        for (auto it = buckets[index].begin(); it != buckets[index].end(); ++it) {
            if (it->first == key) {
                buckets[index].erase(it);
                return;
            }
        }
    }
};
/*
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */