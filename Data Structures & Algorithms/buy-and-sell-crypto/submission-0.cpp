class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int buy = 101;
        int profit = 0;
        for(int i = 0; i < n; i++) {
            if(prices[i] < buy) {
                buy = prices[i];
            }

            profit = max(profit, prices[i] - buy);
        }

        return profit;
    }
};
