class MyHashSet {
    vector<bool>hash;
public:
    MyHashSet() {
        hash.resize(1000001,false);    
    }
    
    void add(int key) {
        hash[key]=true;
    }
    
    void remove(int key) {
        hash[key]=false;
    }
    
    bool contains(int key) {
        return hash[key];
    }
};

/*
Time complexity:
- add, remove, and contains: O(1) average time, since direct index access in a vector is constant time.
Space complexity:
- O(U), where U is the range of possible keys (the vector size). In this implementation, it uses 1,000,001 boolean entries, so space complexity is O(1) relative to the input operations but O(U) overall.
 */