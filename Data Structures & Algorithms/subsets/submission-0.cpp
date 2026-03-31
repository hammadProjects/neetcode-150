class Solution {
public:
    void backtrack(vector<vector<int>>& res, 
        int curr, vector<int>& nums, vector<int> lastSubSet) {
            if(curr >= nums.size()) {
                res.push_back(lastSubSet);
                return;
            }
            // take
            lastSubSet.push_back(nums[curr]);
            backtrack(res, curr+1, nums, lastSubSet);
            // not take
            lastSubSet.pop_back();
            backtrack(res, curr+1, nums, lastSubSet);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> lastSubSet;
        backtrack(res, 0, nums, {});
        return res;
    }
};