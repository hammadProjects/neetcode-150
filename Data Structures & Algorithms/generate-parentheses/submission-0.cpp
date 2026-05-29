class Solution {
public:
    vector<string> parenthesis;
    vector<string> generateParenthesis(int n) {
        int open = 0, close = 0;
        backtrack(n, open + 1, close, "(");
        return parenthesis;
    }

private:
    void backtrack(int n, int open, int close, string cur) {
        if(open == close && close == n) {
            parenthesis.push_back(cur);
            return;
        }

        if(open < n) {
            cur.push_back('(');
            backtrack(n, open + 1, close, cur);
            cur.pop_back();
        }

        if(close < open) {
            cur.push_back(')');
            backtrack(n, open, close + 1, cur);
            cur.pop_back();
        }
    }
};