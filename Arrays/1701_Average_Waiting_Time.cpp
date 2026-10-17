class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        long long wait=0;
        long long curr=0;
        for(vector<int>&vec: customers){
            int start=vec[0];
            int exec=vec[1];
            curr=max((long long)start,curr);
            curr+=exec;
            wait+=curr-start;
        }
        double avg=(double)wait/customers.size();
        return avg;
    }
};
/*Time complexity: O(n), where n is the number of customers. Each customer is processed once in constant time.
Space complexity: O(1) extra space, besides the input, since only a few scalar variables are used.*/