class Solution {
public:
    void heapify(vector<int>&nums,int i,int n){
        int largest=i;
        int left=2*i+1;
        int right=2*i+2;

        if(left<n && nums[left]>nums[largest]){
            largest=left;
        }
        if(right<n && nums[right]>nums[largest]){
            largest=right;
        }

        if(largest!=i){
            swap(nums[largest],nums[i]);
            heapify(nums,largest,n);
        }
    }
    void heapsort(vector<int>&nums){
        int n=nums.size();
        for(int i=n/2 -1; i>=0; i--){
            heapify(nums,i,n);
        }
        for(int end=n-1;end>0;end--){
            swap(nums[end],nums[0]);
            heapify(nums,0,end);
        }
    }
    void sortColors(vector<int>& nums) {
        heapsort(nums);
    }
};
/*Time complexity:
- Building the heap: O(n) using heapify on each non-leaf node.
- Sorting: O(n log n) since each of the n elements is swapped once and heapify costs O(log n).
Overall time complexity: O(n log n).
Space complexity:
- In-place algorithm with heapify using recursion. Recursion depth is O(log n) in the worst case, so auxiliary space is O(log n) due to the call stack. If tail recursion is optimized or implemented iteratively, it could be O(1) auxiliary space.*/