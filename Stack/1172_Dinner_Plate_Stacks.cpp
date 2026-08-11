class DinnerPlates {
public:
    vector<stack<int>>st;
    priority_queue<int,vector<int>,greater<int>>pq;
    int n;
    DinnerPlates(int capacity) {
        n=capacity;
    }
    
    void push(int val) {
        while(!pq.empty() && pq.top()>=st.size()){
            pq.pop();
        }
        if(pq.empty()){
            if(st.empty() || st.back().size()==n){
                st.push_back(stack<int>());
            }
            st.back().push(val);
        }
        else{
            int i=pq.top();
            st[i].push(val);
            if(st[i].size()==n){
                pq.pop();
            }
        }
    }
    
    int pop() {
        while(!st.empty() && st.back().empty()) st.pop_back();
        if(st.empty()) return -1;
        int popped=st.back().top();
        st.back().pop();
        return popped;
    }
    
    int popAtStack(int index) {
        if(index>=st.size() || st[index].empty()) return -1;
        if(index==st.size()-1) return pop();

        bool wasfull=(st[index].size()==n)?true:false;
        int popped=st[index].top();
        st[index].pop();
        if(wasfull) pq.push(index);
        return popped;
    }
};
/*Time complexity:
- push: Amortized O(log k) where k is the number of stacks, due to maintaining a min-heap of non-full stack indices plus occasional pushes to a new stack. Each push operation may push or pop from a stack, and heap adjustments are O(log k). In practice, each element moves at most a small number of times between stacks, but the dominant factor is the heap operations.
- pop: O(1) amortized to access and remove from the last non-empty stack, with occasional cleanup of empty trailing stacks.
- popAtStack: O(1) in the average case, plus O(log k) for pushing back a non-full status into the heap when a stack becomes full. The worst case involves constant work aside from heap push.
Overall, operations are near O(log k) due to the priority queue, with O(1) hints for basic push/pop paths, and k is the number of stacks created.

Space complexity:
- O(k * n) in the worst case, to store up to k stacks each of capacity n. In practice, the total number of elements stored equals the number of pushed values minus pops, and k is the number of stacks created to accommodate capacity n per stack. The auxiliary data structures (the vector of stacks and the min-heap) contribute O(k).*/
/**
 * Your DinnerPlates object will be instantiated and called as such:
 * DinnerPlates* obj = new DinnerPlates(capacity);
 * obj->push(val);
 * int param_2 = obj->pop();
 * int param_3 = obj->popAtStack(index);
 */