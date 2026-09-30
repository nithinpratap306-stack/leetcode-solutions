class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        int sm=INT_MAX,scsm=INT_MAX;
        int lg=INT_MIN,sclg=INT_MIN;
        for(int x: nums){
            if(x>lg){
                sclg=lg;
                lg=x;
            }
            else if(x>sclg){
                sclg=x;
            }
            if(x<sm){
                scsm=sm;
                sm=x;
            }
            else if(x<scsm){
                scsm=x;
            }
        }
        return lg*sclg-sm*scsm;
    }
};
/*Time Complexity: O(n)
Space Complexity: O(1)*/