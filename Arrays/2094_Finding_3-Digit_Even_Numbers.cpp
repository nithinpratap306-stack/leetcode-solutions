class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int>ans;
        int n=digits.size();
        vector<int>freq(10,0);
        for(int i: digits){
            freq[i]++;
        }
        for(int i=1;i<=9;i++){
            for(int j=0;j<=9;j++){
                for(int k=0;k<=8;k+=2){
                    int num=i*100+j*10+k;
                    freq[i]--;
                    freq[j]--;
                    freq[k]--;
                    if(freq[i]>=0 && freq[j]>=0 && freq[k]>=0){
                        ans.push_back(num);
                    }
                    freq[i]++;
                    freq[j]++;
                    freq[k]++;
                }
            }
        }
        return ans;
    }
};
/*Time complexity: O(9 * 10 * 5) = O(450) iterations in the triple loop, but inside each iteration constant work (a few decrements, checks, and push).
 In practice, it is O(1) with respect to the input size, since the loops are bounded by fixed digit ranges.
 However, there is an implicit replication factor: each combination checks and potentially pushes a number, so the worst-case time is proportional to the number of valid 3-digit even numbers that can be formed from digits, which is at most a small constant (about 90 theoretical combinations if unconstrained), but with frequency checks it remains bounded by a small constant.

Space complexity: O(1) extra space besides the input and the output.
 The freq array uses 10 integers, and a small fixed set of local variables.
 The output vector ans can grow but at most holds all valid 3-digit even numbers that can be formed; in the worst case its size is bounded by a constant upper bound based on digit possibilities (still O(1) with respect to input size).*/