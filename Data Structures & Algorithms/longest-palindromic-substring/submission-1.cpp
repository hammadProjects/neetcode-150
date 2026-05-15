class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        pair<int, int> idx = {0, 0};
        int len = 1;
        for(int i = 0; i < n; i++) {
            for(int j = n - 1; j >= i; j--) {
                // now check for palindrome
                if(s[i] != s[j]) continue;
                string substr = s.substr(i, j - i + 1);
                string rev = substr;
                reverse(rev.begin(), rev.end());

                if(rev == substr && len < j - i + 1) {
                    idx.first = i;
                    idx.second = j;
                    len = j - i + 1;
                }
            }
        }

        return s.substr(idx.first, idx.second - idx.first + 1);
    }
};