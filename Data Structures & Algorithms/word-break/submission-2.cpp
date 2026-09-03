class Solution {
    unordered_map<int, bool> dp;
public:
    bool dfs(int idx, string s, vector<string>& wordDict) {
        if(dp.count(idx)) return dp[idx];

        for(string word: wordDict) {
            if(s.substr(idx, word.size()) == word) {
                bool result = dfs(idx + word.size(), s, wordDict);
                if(result) return true;
            }
        }

        return dp[idx] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        dp[s.size()] = true;
        return dfs(0, s, wordDict);
    }
};
