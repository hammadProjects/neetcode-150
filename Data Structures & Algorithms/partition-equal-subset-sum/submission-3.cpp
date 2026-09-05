class Solution {
    unordered_map<int, unordered_map<int, int>> seen;
public:
    bool dfs(vector<int>& nums, int i, int target) {
        if(target < 0) return false;
        if(i == nums.size()) {
            return target == 0;
        }

        if(seen.count(i) && seen[i].count(target)) return seen[i][target];

        return seen[i][target] = dfs(nums, i + 1, target) || dfs(nums, i + 1, target - nums[i]);
    }

    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int n: nums) sum += n;

        if(sum % 2 != 0) return false;
        return dfs(nums, 0, sum / 2);
    }
};