class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n=s.size();
        vector<pair<int,int>>indices(26,{-1,-1});
        int result=0;
        for(int i=0;i<n;i++){
            char ch=s[i];
            int idx=ch-'a';
            if(indices[idx].first==-1) indices[idx].first=i;
            indices[idx].second=i;
        }

        for(int i=0;i<26;i++){
            if(indices[i].first==-1) continue;

            int left_idx=indices[i].first;
            int right_idx=indices[i].second;

            unordered_set<char>st;
            for(int middle=left_idx+1;middle<right_idx;middle++){
                st.insert(s[middle]);
            }
            result+=st.size();
        }
        return result;
    }
};
/*Analysis Result
Time complexity: O(n + k^2) in the worst case, where n is the length of the string and k is the number of distinct characters that appear (up to 26 here). The first loop runs in O(n) to record first and last occurrences. The second loop iterates at most 26 times; for each present character, it scans the substring between its first and last occurrence to collect distinct middle characters, which in the worst case could be up to n in total across all characters, but since each inner loop runs over the gap between first and last occurrences, the total could be O(n) per character in degenerate cases. Practically with only 26 letters, it behaves as O(n) overall plus a small constant factor.

Space complexity: O(1) auxiliary space (besides the output), since we store at most 26 pairs for first/last indices and a few sets per iteration (the set size is at most 26).*/