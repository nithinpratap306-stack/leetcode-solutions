class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string,int>freq;
        for(string c: arr){
            freq[c]++;
        }
        for(string c: arr){
            if(freq[c]==1 && k==1) return c;
            if(freq[c]==1 && k>0) k--;
        }
        return "";
    }
};
/*The function builds a frequency map in O(n) time and O(n) space, where n is the length of arr. 
It then iterates again through arr, checking frequencies in O(1) per element, leading to an overall time complexity of O(n) and auxiliary space complexity of O(n) for the frequency map.
 The second pass is linear and uses constant extra space besides the map.
  In the worst case, if no kth distinct exists, it returns an empty string after the second pass.*/