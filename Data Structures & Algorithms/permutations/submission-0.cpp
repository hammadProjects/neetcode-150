class Solution {
public:
    vector<vector<int>> permutations;
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> curr;
        vector<bool> picked(nums.size(), false);
        backtrack(nums, curr, 0, picked);
        return permutations;
    }

private:
    void backtrack(vector<int>& nums, vector<int>& curr, int idx, vector<bool>& picked) {
        
        if(idx >= nums.size()) {
            permutations.push_back(curr);
            return;
        }

        for(int i = 0; i < nums.size(); i++) {
            if(!picked[i]) {
                picked[i] = true;
                curr.push_back(nums[i]);
                backtrack(nums, curr, idx + 1, picked);
                picked[i] = false;
                curr.pop_back();
            }
        }
    }
};