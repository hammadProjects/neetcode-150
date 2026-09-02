class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size(), longest = INT_MIN;
        int left = -1, right = -1;

        for(int i = 0; i < n; i++) {
            int l = i, r = i;
            while(l >= 0 && r < n && s[l] == s[r]) {
                if(r - l + 1 > longest) {
                    longest = r - l + 1;
                    left = l, right = r;
                }

                l--, r++;
            }

            l = i, r = i + 1;
            while(l >= 0 && r < n && s[l] == s[r]) {
                if(r - l + 1 > longest) {
                    longest = r - l + 1;
                    left = l, right = r;
                }

                l--, r++;
            }
        }

        cout << left << " " << right << endl;
        return s.substr(left, right - left + 1);
    }
};