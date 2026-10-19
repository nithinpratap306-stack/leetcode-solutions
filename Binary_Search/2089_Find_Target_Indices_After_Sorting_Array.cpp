zclass Solution {
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
    vector<int>ans;
    vector<int> binsrch(vector<int>nums,int target){
        int low=0;
        int high=nums.size()-1;
        int first=-1;
        while(low<=high){
            int mid=(low+high)/2;

            if(target==nums[mid]){
                first=mid;
                high=mid-1;
            }
            else if(target>nums[mid]){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        if(first==-1) return ans;
        for(int i=first;i<nums.size() && nums[i]==target;i++){
            ans.push_back(i);
        }
        return ans;
    }
    vector<int> targetIndices(vector<int>& nums, int target) {
        heapsort(nums);
        return binsrch(nums,target);
    }
};
/*Time complexity:
- Heapsort construction: building the max-heap with heapify from n/2 - 1 down to 0 takes O(n log n) in total, though the actual build is O(n). In this implementation, each heapify can take up to O(log n), and the loop runs about n/2 times, so the total is O(n log n).
- Heapsort extraction phase: for each end from n-1 down to 1, swap and heapify the root over a shrinking heap, which is O(log n) per step, resulting in O(n log n).
- Binary search: on the sorted array of size n, O(log n).
- Collecting indices after finding first occurrence: in the worst case, if the target appears k times, collecting them costs O(k). In addition, the for loop scans consecutive equal elements starting from first until a different value is found, which is O(k). k ≤ n.

Overall time: O(n log n) for sorting plus O(log n) for binary search plus O(k) for collecting, which is O(n log n + k). In the worst case where k = n, it becomes O(n log n).

Space complexity:
- The algorithm sorts in place, using the input vector without extra data structures besides recursion stack in heapify. The recursive heapify depth is O(log n), so auxiliary space due to recursion is O(log n). If iterative heapify were used, it could be O(1) extra space.
- The binsrch function stores the result in a member vector ans; its size is k, so extra space is O(k). The final output size dominates, so total auxiliary space is O(k) plus O(log n) call stack. If we count only additional space beyond the output, it's O(log n).*/