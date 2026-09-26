class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int mx=-1;
        int curr=-1;
        for(int i=arr.size()-1;i>=0;i--){
            mx=max(mx,curr);
            curr=arr[i];
            arr[i]=mx;
        }
        return arr;
    }
};
/*Time complexity: O(n), where n is the length of arr. The loop traverses the array once.
Space complexity: O(1) extra space. The algorithm uses a few scalar variables and modifies the input array in place.*/