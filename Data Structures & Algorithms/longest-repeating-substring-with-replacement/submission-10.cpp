class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        unordered_map<char, int> freq;
        int maxi = 0;
        int left = 0, maxF = 0;

        for(int right = 0; right < n; right++) {
            char ch = s[right];
            freq[ch]++;
            maxF = max(maxF, freq[ch]);

            while((right - left + 1) - maxF > k) {
                freq[s[left]]--;
                left++;
            }

            maxi = max(maxi, right - left + 1);
        }

        return maxi;
    }
};