class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int low = 0, high = 0, largest = 0;
        unordered_map<char, int> seen;

        while(high < n) {
            char curr = s[high];
            // Shrink
            while(seen[s[high]]) {
                seen.erase(s[low]);
                low++;
            }

            // Expand
            seen[curr] = 1;

            // Update
            largest = max(largest, high - low + 1);
            high++;
        }

        return largest;
    }
};