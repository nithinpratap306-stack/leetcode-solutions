class MyHashMap {
    vector<int> key;
    vector<int> value;

public:
    MyHashMap() {
        key.resize(1000001, -1);
        value.resize(1000001, -1);
    }

    void put(int k, int v) {
        key[k] = k;
        value[k] = v;
    }

    int get(int k) {
        if(key[k] == -1)
            return -1;

        return value[k];
    }

    void remove(int k) {
        key[k] = -1;
        value[k] = -1;
    }
};
/*Time complexity:
- put: O(1) average, since it directly assigns at index k.
- get: O(1) in all cases, since it checks key[k] and returns value[k] or -1.
- remove: O(1), as it directly resets at index k.

Space complexity:
- Uses two vectors of size 1,000,001 (indices 0 to 1,000,000), plus a constant offset. So O(MAX_KEY) space, where MAX_KEY = 1,000,001. This is linear in the maximum possible key value, irrespective of how many keys are actually used.*/