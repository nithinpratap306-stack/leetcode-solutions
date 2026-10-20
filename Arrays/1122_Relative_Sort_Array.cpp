class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int,int>freq;
        for(int x: arr1){
            freq[x]++;
        }
        int ind=arr1.size()-1;
        for(int i=arr1.size()-1;i>=0;i--){
            if(find(arr2.begin(),arr2.end(),arr1[i])==arr2.end()){
                arr1[ind--]=arr1[i];
            }
        }
        int index=ind+1;
        for(int i=index;i<arr1.size();i++){
            for(int j=i;j<arr1.size();j++){
                if(arr1[i]>arr1[j]){
                    int temp=arr1[i];
                    arr1[i]=arr1[j];
                    arr1[j]=temp;
                }
            }
        }
        ind=0;
        for(int x: arr2){
            for(int i=0;i<freq[x];i++){
                arr1[ind++]=x;
            }
        }
        return arr1;
    }
};
/*Time complexity:
- Building freq map: O(n), where n = arr1.size().
- The loop that moves non-arr2 elements to the tail uses find over arr2 (O(m) per check) for each of n elements, giving O(n*m) in the worst case.
- The sort of the tail portion: O(t^2) where t is the number of elements not in arr2; t ≤ n.
- The final placement of elements from arr2: O(n) as it writes each element according to freq.

Overall, the dominant term is O(n*m) in the worst case plus the O(t^2) tail sort. In typical scenarios where m (size of arr2) is much smaller than n, the complexity is roughly O(n + n*m + t^2) but in the worst case it can degrade to O(n*m + n^2).

Space complexity:
- freq map stores counts for distinct elements from arr1: O(k), where k ≤ n.
- Additional in-place operations use O(1) extra space beyond the input array, so the auxiliary space is O(k) for the map. Overall space complexity is O(n) in the worst case due to the map, but typically O(number of distinct elements in arr1).*/