class Solution {
public:
    vector<int> dp;
    int rob(vector<int>& nums) {
       int n = nums.size();
       dp = vector<int>(n, -1);

       dfs(nums, dp, 0);
       return dp[0];
    }

private:
    int dfs(vector<int>& nums, vector<int>& dp, int idx) {
        if(idx >= nums.size()) return 0;
        if(dp[idx] != -1) return dp[idx];

        int plusOne = dfs(nums, dp, idx + 1);
        int plusTwo = dfs(nums, dp, idx + 2);

        return dp[idx] = max(
            nums[idx] + plusTwo,
            plusOne
        );
    }
};