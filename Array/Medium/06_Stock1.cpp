
// Keep track of min on the left of ith elemnt 
// Sell on ith day
// buy on the day with min price before ith day
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int stprice = prices[0];
        int maxProfit = INT_MIN;
        for(int i=0; i<prices.size();i++){
            if(prices[i] < stprice) stprice = prices[i]; // Keep track of min price in the left 
            else maxProfit = max(maxProfit, prices[i] - stprice);
        }
        return maxProfit;
    }
};
