class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int>freq;

        int sum=0;
        int ans=0;

        freq[0]=1;

        for(int x: nums){
            sum+=x;

            int rem = sum % k;

            if(rem < 0){
                rem+=k;
            }

            ans+=freq[rem];

            freq[rem]++;
        }
        return ans;
    }
};
/*Time complexity: O(n), where n is the length of nums. Each element is processed once and map lookups/updates are amortized O(1).
Space complexity: O(k) in the worst case, due to storing frequencies of remainders in the unordered_map (though in practice it will be at most min(n, k) distinct remainders).*/