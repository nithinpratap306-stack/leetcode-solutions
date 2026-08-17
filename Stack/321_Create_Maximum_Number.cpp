class Solution {
public:
    vector<int> solve(int k, vector<int>&nums){
        int n=nums.size();
        if(k>n) return {};
        vector<int>ans;
        ans.push_back(nums[0]);
        for(int i=1;i<n;i++){
            while(!ans.empty() && ans.back()<nums[i] && ans.size()-1+n-i>=k){
                ans.pop_back();
            }
            ans.push_back(nums[i]);
        }
        while(ans.size()>k){
            ans.pop_back();
        }
        return ans;
    }
    void merge(vector<int> &ans,vector<int> &v1,vector<int>&v2){
        int m=v1.size();
        int n=v2.size();
        int i=0;
        int j=0;
        while(i<m && j<n){
            if(v1[i]==v2[j]){
                int tempi=i;
                int tempj=j;
                while(tempi<m && tempj<n && v1[tempi]==v2[tempj]){
                    tempi++;
                    tempj++;
                }
                if(tempj==n){
                    ans.push_back(v1[i]);
                    i++;
                }
                else if(tempi==m){
                    ans.push_back(v2[j]);
                    j++;
                }
                else if(v1[tempi]>v2[tempj]){
                    ans.push_back(v1[i]);
                    i++;
                }
                else{
                    ans.push_back(v2[j]);
                    j++;
                }
            }
            else if(v1[i]<v2[j]){
                ans.push_back(v2[j]);
                j++;
            }
            else{
                ans.push_back(v1[i]);
                i++;
            }
        } 
        while(i<m){
            ans.push_back(v1[i]);
            i++;
        }
        while(j<n){
            ans.push_back(v2[j]);
            j++;
        }
        // return ans;
    }
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int>ans;
        for(int i=0;i<=k;i++){
            vector<int>temp1=solve(i,nums1);
            vector<int>temp2=solve(k-i,nums2);
            vector<int>temp;
            merge(temp,temp1,temp2);
            if(temp.size()==k) ans=max(ans,temp);
        }
        return ans;
    }
};
/*- solve
  - n = nums.size()
  - It builds a monotonic decreasing stack-like sequence of length k from nums.
  - Each element can be pushed and popped at most once. The while loop may pop each element multiple times, but overall each element is pushed once and popped at most once.
  - Time complexity: O(n)
  - Space complexity: O(k) for the answer vector (and a few extra variables), i.e., O(k)

- merge
  - This function merges two sequences v1 and v2 into an answer vector ans by comparing elements and handling equal-prefix ties with lookahead.
  - In the worst case, it processes each element of v1 and v2 a constant number of times, with some lookahead when equal.
  - Time complexity: O(m + n) where m = v1.size(), n = v2.size()
  - Space complexity: O(1) extra besides the output vector ans (besides the existing contents of ans), i.e., O(1) auxiliary space plus the space for ans.

Overall:
- Time: O(n) for solve plus O(m + n) for merge (where m and n are the sizes of the merged halves). If used as part of a larger algorithm that repeatedly merges, total time would depend on how many merges and the sizes involved.
- Space: O(k) for solve’s output, with O(1) extra auxiliary space for merge aside from the output vector.*/