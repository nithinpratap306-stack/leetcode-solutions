class RandomizedSet {
public:
    vector<int>nums;
    unordered_map<int,int>mp;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(mp.find(val)!=mp.end()) return false;
        nums.push_back(val);
        mp[val]=nums.size()-1;
        return true;
    }
    
    bool remove(int val) {
        if(mp.find(val)==mp.end()) return false;
        int i=mp[val];
        swap(nums[i],nums[nums.size()-1]);
        int swapped=nums[nums.size()-1];
        mp[nums[i]]=i;
        mp.erase(val);
        nums.pop_back();
        return true;
    }
    
    int getRandom() {
        int i=rand() % nums.size();
        return nums[i];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

/*- insert(val): O(1) expected time. Uses unordered_map lookup and push_back to vector.
- remove(val): O(1) expected time. Finds index via map, swaps with last element in vector, updates the moved element’s index in the map, erases the removed value from the map, and pops back.
- getRandom(): O(1) time. Selects a random index in the current vector.

Space complexity: O(n), where n is the number of elements stored. Uses a vector to store elements and an unordered_map to store value-to-index mappings.*/