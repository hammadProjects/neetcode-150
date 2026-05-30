class Solution {
public:
    // unordered_set<vector<int>> unique;
    vector<vector<int>> combinations;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> cur;
        backtrack(0, target, candidates, cur);

        return combinations;
    }

private:
    void backtrack(int idx, int target, vector<int>& candidates, vector<int>& cur) {
        if(target == 0) {
            combinations.push_back(cur);
            return;
        }

        for(int i = idx; i < candidates.size(); i++) {
            if(i > idx && candidates[i] == candidates[i - 1]) continue;
            int curSum = target - candidates[i];
            if(curSum < 0) break;

            cur.push_back(candidates[i]);
            backtrack(i + 1, curSum, candidates, cur);
            cur.pop_back();
        }
    }
};