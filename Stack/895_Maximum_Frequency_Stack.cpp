class FreqStack {
public:
// Time complexity:
// - push: O(1) average. It updates two hash maps and a stack, all constant-time operations.
// - pop: O(1) amortized. Accesses the stack corresponding to the current max frequency, pops one element, updates maps, and possibly decrements maxfreq. All constant-time in expectation.

// Space complexity:
// - O(n) in the worst case, where n is the number of elements pushed. freq stores counts for each distinct value; group stores stacks of values grouped by frequency. In the worst-case scenario (all values distinct), there are as many entries as elements, and the total number of stored ints is proportional to n.
    unordered_map<int,int>freq;
    unordered_map<int,stack<int>>group;
    int maxfreq=0;
    FreqStack() {
        
    }
    
    void push(int val) {
        freq[val]++;
        group[freq[val]].push(val);
        if(freq[val]>maxfreq){
            maxfreq=freq[val];
        }
    }
    
    int pop() {
        int x=group[maxfreq].top();
        group[maxfreq].pop();
        freq[x]--;
        if(group[maxfreq].empty()){
            maxfreq--;
        }
        return x;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */