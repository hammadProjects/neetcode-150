class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;
        for(string s: strs) {
            vector<int> counts(26, 0);
            for(char c: s) counts[c - 'a']++;
            string key = to_string(counts[0]);
            for(int i = 0; i < 26; i++) 
                key += ',' + to_string(counts[i]);

            groups[key].push_back(s);
        }

        vector<vector<string>> ans;
        for(auto& grp: groups) {
            ans.push_back(grp.second);
        }

        return ans;
    }
};