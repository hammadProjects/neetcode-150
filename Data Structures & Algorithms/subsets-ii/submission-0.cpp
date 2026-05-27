class Solution {
public:
    set<vector<int>> uniques;
    vector<vector<int>> subsets;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> curr;
        sort(nums.begin(), nums.end());
        backtrack(nums, curr, 0);
        
        for(vector<int> ss: uniques) {
            subsets.push_back(ss);
        }

        return subsets;
    }

private:
    void backtrack(vector<int>& nums, vector<int>& curr, int idx) {
        if(idx >= nums.size()) {
            uniques.insert(curr);
            return;
        }

        // Take
        curr.push_back(nums[idx]);
        backtrack(nums, curr, idx + 1);
        // Dont Take
        curr.pop_back();
        backtrack(nums, curr, idx + 1);
    }
};