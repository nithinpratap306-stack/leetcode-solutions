class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int elem=0;
        int cnt=0;
        for(int i: nums){
            if(cnt==0){
                cnt=1;
                elem=i;
            }
            else{
                if(elem==i) cnt++;
                else cnt--;
            }
        }
        cnt=0;
        for(int i: nums){
            if(elem==i) cnt++;
        }
        if(cnt> nums.size()/2) return elem;
        return -1;
    }
};
/*Time complexity: O(n). The first loop scans the array once to find a candidate using Boyer-Moore. The second loop scans again to verify the candidate, giving overall O(n).
Space complexity: O(1). Only a few integer variables are used, regardless of input size.*/