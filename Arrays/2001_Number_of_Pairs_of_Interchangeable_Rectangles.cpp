class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        unordered_map<long long,int>mp;
        for(const auto &vec: rectangles){
            int a=vec[0];
            int b=vec[1];
            
            int g=gcd(a,b);
            a/=g;
            b/=g;

            long long c=1ll*a*1000000001+b;
            mp[c]++;
        }
        long long ans=0;
        for(auto &[a,b]:mp){
            ans+=1ll*b*(b-1)/2;
        }
        return ans;
    }
};
/*We compute normalized side ratios for each rectangle by dividing by gcd(a,b). Each rectangle requires O(1) gcd time. We insert into an unordered_map with key constructed from a and b. Overall time: O(n) average, where n is number of rectangles, assuming average O(1) unordered_map operations. In the worst case of hash collisions, operations degrade, but typically considered O(n).
Space: O(n) for the map storing at most n distinct normalized keys. The final accumulation is O(m) where m is number of distinct keys (≤ n). Overall: time complexity O(n) average, space complexity O(n).*/