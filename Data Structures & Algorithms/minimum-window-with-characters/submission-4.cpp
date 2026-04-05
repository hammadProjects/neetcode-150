class Solution {
public:
    bool isWindowCorrect(vector<int> &window, vector<int> &countT) {
        for(int i = 0; i < 256; i++) {
            if(countT[i] > window[i]) {
                return false;
            }
        }

        return true;
    }

    string minWindow(string s, string t) {
        if(t.empty()) return "";
        if(s == t) return t;
        int n = s.size();
        int mini = INT_MAX;
        pair<int, int> indices = {-1, -1};
        vector<int> countT(256, 0);
        vector<int> window(256, 0);
        for(char ch: t) {
            countT[ch]++;
        }

        int left = 0;
        for(int right = 0; right < n; right++) {
            // Expand
            window[s[right]]++;

            // Check Freq
            while(isWindowCorrect(window, countT)) {
                window[s[left]]--;
                int len = right - left + 1;
                if(mini > len) {
                    mini = len;
                    indices.first = left;
                    indices.second = right;
                }

                left++;
            }
        }

        return mini == INT_MAX ? "" : s.substr(indices.first, mini);
    }
};