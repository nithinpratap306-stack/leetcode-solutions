class Solution {
public:
    void heapify(vector<int>& nums, int n,int i){
        int left=2*i+1;
        int right=2*i+2;
        int largest=i;

        if(left<n && nums[left]>nums[largest]){
            largest=left;
        }
        if(right<n && nums[right]>nums[largest]){
            largest=right;
        }

        if(largest!=i){
            swap(nums[largest],nums[i]);
            heapify(nums,n,largest);
        }
    }
    void heapsort(vector<int>&nums){
        int n=nums.size();
        for(int i=n/2 -1;i>=0;i--){
            heapify(nums,n,i);
        }
        for(int end=n-1;end>0;end--){
            swap(nums[0],nums[end]);
            heapify(nums,end,0);
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        heapsort(nums);
        return nums;
    }
};
/*Time complexity:
- Building the max-heap: O(n) time, since heapify is called for each non-leaf node and the total work sums to O(n).
- Sorting (repeatedly extracting max): O(n log n) since we perform n-1 extractions, each with a heapify of height log n.
Overall time complexity: O(n log n).
Space complexity:
- In-place sort; no extra data structures besides recursion stack for heapify.
- Recursion depth of heapify is O(log n) in the worst case.
Overall space complexity: O(log n) due to the recursive calls (auxiliary space). If tail recursion is optimized or heapify is implemented iteratively, it could be O(1) auxiliary space.*/