class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int,int>mp;
        for(int i: arr){
            mp[i]++;
        }
        sort(arr.begin(),arr.end());
        for(int i=arr.size()-1;i>=0;i--){
            if(mp[arr[i]]==arr[i]){
                return arr[i];
            }
        }
        return -1;
    }
};
/*Time complexity: O(n log n) due to the sort step, where n is the size of arr. Building the frequency map is O(n). The final reverse scan is O(n).
Space complexity: O(k) for the frequency map, where k is the number of distinct values in arr. In the worst case, O(n). The sorting uses in-place sort on the vector, so additional space beyond the map is O(1) aside from the map.*/