class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(101, 0);
        return min(
            minCost(cost, dp, 0),
            minCost(cost, dp, 1)
        );
    }

private:
    int minCost(vector<int>& cost, vector<int>& dp, int idx) {
        if(idx >= cost.size()) return 0;
        if(dp[idx]) return dp[idx];

        return dp[idx] =  cost[idx] + min(
            minCost(cost, dp, idx + 1),
            minCost(cost, dp, idx + 2)
        );
    }
};