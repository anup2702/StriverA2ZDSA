class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int stprice = prices[0];
        int maxProfit = INT_MIN;
        for(int i=0; i<prices.size();i++){
            if(prices[i] < stprice) stprice = prices[i];
            else maxProfit = max(maxProfit, prices[i] - stprice);
        }
        return maxProfit;
    }
};


