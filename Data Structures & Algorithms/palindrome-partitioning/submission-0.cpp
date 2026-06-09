class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> palindromes;
        vector<string> path;
        backtrack(s, 0, path, palindromes);
        return palindromes;
    }

private:
    bool isPalindrome(string s, int l, int r) {

        while(l < r) {
            if(s[l] != s[r]) return false;
            l++, r--;
        }

        return true;
    }

    void backtrack(string s, int idx, vector<string>& path, vector<vector<string>>& palindromes) {
        if(idx == s.size()) {
            palindromes.push_back(path);
            return;
        }

        for(int i = idx; i < s.size(); i++) {
            if(isPalindrome(s, idx, i)) {
                path.push_back(s.substr(idx, i - idx + 1));
                backtrack(s, i + 1, path, palindromes);
                path.pop_back();
            }
        }
    }
};