
class MyHashSet {
private:
    vector<bool> table;

public:
    MyHashSet() {
        table.resize(1000001, false);
    }
    
    void add(int key) {
        table[key] = true;
    }
    
    void remove(int key) {
        table[key] = false;
    }
    
    bool contains(int key) {
        return table[key];
    }
};