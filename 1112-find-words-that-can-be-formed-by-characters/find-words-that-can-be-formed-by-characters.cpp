class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int cnt = 0;

        for (string s : words) {
            unordered_map<char, int> counts;

            for (char ch : chars)
                counts[ch]++;

            bool possible = true;

            for (char ch : s) {
                if (counts[ch] > 0) {
                    counts[ch]--;
                } else {
                    possible = false;
                    break;
                }
            }

            if (possible)
                cnt += s.size();
        }

        return cnt;
    }
};