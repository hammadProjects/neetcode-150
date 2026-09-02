class Solution {
    vector<int> dp;
public:
    int decodings(string s, int idx) {
        if(dp[idx] != -1) return dp[idx];
        if(s[idx] == '0') return 0;

        int res = decodings(s, idx + 1);
        if(idx + 1 < s.size() && 
        (s[idx] == '1' || (s[idx] == '2' && s[idx + 1] <= '6'))) {
            res += decodings(s, idx + 2);
        }

        return dp[idx] = res;
    }

    int numDecodings(string s) {
        dp.resize(s.size() + 1, -1);
        dp[s.size()] = 1;
        return decodings(s, 0);
    }
};