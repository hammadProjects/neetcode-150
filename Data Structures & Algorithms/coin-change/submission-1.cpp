class Solution {
    unordered_map<int, int> dp;
public:
    int dfs(vector<int>& coins, int amount) {
        if(dp.count(amount)) return dp[amount];

        int res = INT_MAX;
        for(int coin: coins) {
            if(amount - coin >= 0) {
                int result = dfs(coins, amount - coin);
                if(result != INT_MAX) {
                    res = min(res, 1 + result);
                }
            }
        }

        return dp[amount] = res;
    }

    int coinChange(vector<int>& coins, int amount) {
        dp[0] = 0;
        int minCoins = dfs(coins, amount);
        return minCoins == INT_MAX ? -1 : minCoins;
    }
};