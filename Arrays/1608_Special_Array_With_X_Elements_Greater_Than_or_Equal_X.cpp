class Solution {
public:
    int specialArray(vector<int>& nums) {
        for(int i=nums.size();i>0;i--){
            int cnt=0;
            for(int x: nums){
                if(x>=i) cnt++;
            }
            if(cnt==i) return i;
        }
        return -1;
    }
};
/*Complexity
- Time: (O(n^2)) — you check all (n) elements for each of up to (n) candidate values.
- Auxiliary space: (O(1)) — only the counter and loop variables are used.*/