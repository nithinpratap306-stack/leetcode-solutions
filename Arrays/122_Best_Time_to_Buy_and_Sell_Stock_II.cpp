class Solution {
public:
    int maxProfit(vector<int>& prices) {
        long aheadBuy,aheadNotBuy,currBuy,currNotBuy;
        aheadBuy=aheadNotBuy=0;
        for(int ind = prices.size()-1;ind>=0;ind--){
            currBuy=max(-prices[ind]+aheadNotBuy , aheadBuy);
            currNotBuy=max(prices[ind]+aheadBuy, aheadNotBuy);

            aheadBuy=currBuy;
            aheadNotBuy=currNotBuy;
        }
        return aheadBuy;
    }
};
/*Time complexity: O(n), where n is the number of prices. The loop runs once per element and each iteration does a constant amount of work.
Space complexity: O(1) extra space, aside from the input, since only a fixed number of variables (aheadBuy, aheadNotBuy, currBuy, currNotBuy) are used.*/