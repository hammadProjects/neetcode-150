class Solution {
public:
    vector<vector<int>> combinations;
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> comb;
        backtrack(comb, nums, 0, 0, target);

        return combinations;
    }

private:
    void backtrack(vector<int>& comb, vector<int> nums, int sum, int idx, int target) {
        if(sum == target) {
            combinations.push_back(comb);
            return;
        }

        if(sum > target || idx >= nums.size()) return;

        comb.push_back(nums[idx]);
        backtrack(comb, nums, sum + nums[idx], idx, target);
        comb.pop_back();
        backtrack(comb, nums, sum, idx + 1, target);
    }
};
