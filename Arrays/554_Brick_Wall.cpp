class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<long long,long long>mp;
        for(const vector<int>& lt : wall){
            long long cm=0;
            for(int i=0;i<lt.size()-1;i++){
                cm+=lt[i];
                mp[cm]++;
            }
        }
        int n=wall.size();
        long long mx=0;
        for(const auto &[key,value]: mp){
            mx=max(value,mx);
        }
        return n-mx;
    }
};
/*Time complexity: O(W), where W is the total number of bricks across all rows (sum of wall[i].size()) because we traverse each brick once except the last brick in each row, performing constant-time map updates.
Space complexity: O(K), where K is the number of distinct edge positions (partial sums) across all rows (the size of the map). In the worst case, K can be as large as W, so space is O(W) in the worst case.*/