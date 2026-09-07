class Solution {
    vector<vector<int>> ans;
public:
    void backtrack(int i, vector<int>& nums, vector<int>& cur) {
        if(i == nums.size()) {
            ans.push_back(cur);
            return;
        }

        // take
        cur.push_back(nums[i]);
        backtrack(i + 1, nums, cur);
        cur.pop_back();

        // not take
        backtrack(i + 1, nums, cur);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> cur;
        backtrack(0, nums, cur);
        return ans;
    }
};