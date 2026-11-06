class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cnt1=0,cnt2=0;
        int el1=INT_MIN,el2=INT_MIN;
        vector<int>ans;
        int min=nums.size()/3;
        
        for(int i: nums){
            if(cnt1==0 && i!=el2){
                el1=i;
                cnt1=1;
            }
            else if(cnt2==0 && i!=el1){
                el2=i;
                cnt2=1;
            }
            else if(i==el1) cnt1++;
            else if(i==el2) cnt2++;
            else{
                cnt1--;
                cnt2--;
            }
        }
        cnt1=0;
        cnt2=0;

        for(int i: nums){
            if(el1==i) cnt1++;
            if(el2==i) cnt2++;
        }

        if(cnt1>min) ans.push_back(el1);
        if(cnt2>min) ans.push_back(el2);
        return ans;
    }
};
/*Time complexity: O(n). The algorithm makes two linear passes over the input array: one to find potential candidates and one to verify them.
Space complexity: O(1). It uses a constant number of extra variables (cnt1, cnt2, el1, el2, and a small result vector of at most two elements, but additional space is independent of n).*/