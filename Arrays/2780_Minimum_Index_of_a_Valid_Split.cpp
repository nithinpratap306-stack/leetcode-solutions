class Solution {
public:
    int moorevotingalgo(vector<int>& nums){
        int elem=-1;
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            if(cnt==0){
                elem=nums[i];
                cnt=1;
            }
            else if(nums[i]==elem) cnt++;
            else cnt--;
        }
        return elem;
    }
    int minimumIndex(vector<int>& nums) {
        int maj_elem=moorevotingalgo(nums);
        int n=nums.size();
        
        int max_freq=0;
        for(int i: nums){
            if(i==maj_elem) max_freq++;
        }

        int prefix=0;
        for(int i=0;i<n;i++){
            if(nums[i]==maj_elem){
                prefix++;
                max_freq--;
            }

            if( (prefix>(i+1)/2) && (max_freq>(n-i-1)/2) ){
                return i;
            }
        }
        return -1;
    }
};
/*Time complexity:
- Moore’s voting algorithm: O(n) time.
- Counting frequency of the candidate: O(n).
- Single pass to find the minimum index with the required condition: O(n).
Total time: O(n).

Space complexity:
- Uses a constant number of extra variables: O(1) space.*/