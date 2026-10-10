class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int a=-1,b=-1;
        vector<int>freq(nums.size(),0);
        for(int x: nums){
            freq[x-1]++;
        }
        for(int i=0;i<nums.size();i++){
            if(freq[i]==0) b=i+1;
            if(freq[i]==2) a=i+1;
        }
        return {a,b};
    }
};
/*Time: (O(n))
Auxiliary space: (O(n)) for the frequency array.*/