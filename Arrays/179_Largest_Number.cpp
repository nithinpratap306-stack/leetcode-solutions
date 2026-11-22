class Solution {
public:
    static bool compare(int a , int b){
        return to_string(a)+to_string(b)>to_string(b)+to_string(a);
    }
    string largestNumber(vector<int>& nums) {
        string ans="";
        sort(nums.begin(),nums.end(),compare);
        for(int i: nums){
            ans+=to_string(i);
        }
        if(ans[0]=='0') return "0";
        return ans;
    }
};
/*Time complexity: O(n log n) due to sorting n numbers. The comparator compare(a,b) concatenates strings and compares, which in the worst case takes O(k) where k is the average number of digits per number (roughly constant for typical int ranges). Overall, O(n log n) time with a small constant factor from string operations.
Space complexity: O(1) auxiliary space besides the output string. Sorting may use O(log n) call stack space for the sort algorithm (in-place sort like introsort), and the output string grows to the final result. If you count the returned string, total space is O(n * d) where d is average digit length, but auxiliary extra space apart from output is O(log n).*/