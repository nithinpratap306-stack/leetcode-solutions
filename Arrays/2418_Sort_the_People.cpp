class Solution {
public:
    void heapify(vector<string>&names,vector<int>&heights,int n,int i){
        int largest=i;
        int left=2*i+1;
        int right=2*i+2;

        if(left<n && heights[largest]>heights[left]){
            largest=left;
        }

        if(right<n && heights[largest]>heights[right]){
            largest=right;
        }

        if(largest!=i){
            swap(heights[largest],heights[i]);
            swap(names[largest],names[i]);
            heapify(names,heights,n,largest);
        }
    }
    void heapsort(vector<string>&names,vector<int>&heights){
        int n=names.size();
        for(int i=n/2 -1;i>=0;i--){
            heapify(names,heights,n,i);
        }
        for(int end=n-1;end>0;end--){
            swap(heights[0],heights[end]);
            swap(names[0],names[end]);
            heapify(names,heights,end,0);
        }
    }
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        heapsort(names,heights);
        return names;
    }
};
/*Time complexity:
- Building the heap: O(n) time, where n is the number of elements, since heapify is called for each non-leaf node once.
- Sorting phase: O(n log n) time, as we repeatedly extract the max (root) and heapify the reduced heap.
Overall time complexity: O(n log n).

Space complexity:
- In-place sorting; no extra data structures proportional to n are allocated beyond a few local variables. Therefore, auxiliary space is O(1).
- The input vectors are modified in place; the total additional space used is O(1).*/