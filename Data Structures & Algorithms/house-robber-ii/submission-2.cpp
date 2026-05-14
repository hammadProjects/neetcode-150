class Solution {
public:
    vector<int> dp1;
    vector<int> dp2;
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];

        dp1.resize(n, -1);
        dp2.resize(n, -1);
        return max(
            dfs(nums, dp1, n - 1, 0),
            dfs(nums, dp2, n, 1)
        );
    }

private:
    int dfs(vector<int>& nums, vector<int>& dp, int n, int idx) {
        if(idx >= n) return 0;
        if(dp[idx] != -1) return dp[idx];

        return dp[idx] = max(
            nums[idx] + dfs(nums, dp, n, idx + 2),
            dfs(nums, dp, n, idx + 1)
        );
    }
};